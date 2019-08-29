#pragma once
using namespace System;
using namespace System::Threading;
using namespace System::Runtime::Remoting::Messaging;

ref class DelegateDemo
{
public:
	int x;

	static void HelloStatic()
	{
		Console::WriteLine("I am a static method");
	}

	void HelloInstance()
	{
		Console::WriteLine("I am an instance method with a value of {0}", x);
	}
};

namespace DelegatesSynchronous
{
	delegate void MyDelegate();

	void DemoStatic()
	{
		MyDelegate^ invoker = gcnew MyDelegate(&DelegateDemo::HelloStatic);
		invoker();
	}

	void DemoInstance()
	{
		DelegateDemo^ obj = gcnew DelegateDemo();
		obj->x = 10;
		MyDelegate^ invoker = gcnew MyDelegate(obj, &DelegateDemo::HelloInstance);
		invoker;
	}

	void HelloWorld()
	{
		Console::WriteLine("Hello world");
	}

	void DemoChain()
	{
		MyDelegate^ invoker = gcnew MyDelegate(&DelegateDemo::HelloStatic);
		invoker += gcnew MyDelegate(&HelloWorld);
		invoker();
		invoker->Combine(gcnew MyDelegate(&HelloWorld));
		invoker();
		invoker -= gcnew MyDelegate(&HelloWorld);
		invoker();
	}
}

namespace DelegatesAsynchronous
{
	delegate int MyDelegate(int);

	int Pause(int wait)
	{
		Console::WriteLine("Starting wait");
		Thread::Sleep(wait);
		Console::WriteLine("End wait");
		return wait;
	}

	int ThreeTimesX(int num)
	{
		Pause(5000);
		return num * 3;
	}

	void CallBack(IAsyncResult^ result)	// callback function to be used by the asyn invocation of delegate
	{
		// IAsyncResult^ result represents the result of the delegate invocation
		
		// it has to be cast in to AsyncResult in order to get the delegate
		AsyncResult^ castResult = dynamic_cast<AsyncResult^>(result);
		Object^ delegateRaw =  castResult->AsyncDelegate;	// get the delegate from the result
		MyDelegate^ delegateObj = safe_cast<MyDelegate^>(delegateRaw);	// cast the delegate to the correct delegate type
		int delegateResult = delegateObj->EndInvoke(result);	// get the delegate result by invoking EndInvoke

		Console::WriteLine("Delgate result: {0}", delegateResult);	// do whatever with the result
	}

	void DemoAsync()
	{
		MyDelegate^ invoker = gcnew MyDelegate(&Pause);
		//invoker += gcnew MyDelegate(&ThreeTimesX);	// BeginInvoke allows only on method per thread

		AsyncCallback^ callback = gcnew AsyncCallback(&CallBack);

		Console::WriteLine("Before invoking delegate");
		invoker->BeginInvoke(3000, callback, nullptr);
		Console::WriteLine("After invoking delegate");
		Console::ReadKey(false);	// wait here! or thread pool worker might not run
	}

}