// HelloWorld.cpp : main project file.

#include "stdafx.h"
#include "UnmanagedSquare.h"

using namespace System;

namespace MyNamespace
{
	void HelloManaged()
	{
		Console::WriteLine(L"Hello managed world");
	}

	void HelloUnmanaged()
	{
		std::cout << "Hello unmanaged world" << std::endl;
	}

	void DemoUnmanagedSquareByValue()
	{
		UnmanagedSquare square(2.5);	// creating an unmanaged object on the stack (by value)
		std::cout << "Area: " << square.CalculateArea() << std::endl;
		// no need to delete this object since it will popped off the stack when the function finished execution
	}

	void DemoUnmanagedSquareByReference()
	{
		UnmanagedSquare* square = new UnmanagedSquare(4.5);	// created an unmanaged object on unmanaged heap. This heap is not garbage collected by the GC. So this object has to be deleted manually or it will cause memory leakage.

		UnmanagedSquare& squareRef = *square;	// created a reference to the square object

		Console::WriteLine(String::Format(L"Area: {0}", squareRef.CalculateArea()));
		std::cout << "Area: " << square->CalculateArea() << std::endl;

		delete square;	// it will be memory leakage if we don't do this here.
		//delete &squareRef;	// or we could do this; the result is same
	}
}

int main(array<System::String ^> ^args)
{

	MyNamespace::HelloManaged();
	MyNamespace::HelloUnmanaged();

	MyNamespace::DemoUnmanagedSquareByReference();

	std::cout << std::endl;

	MyNamespace::DemoUnmanagedSquareByValue();

	Console::ReadKey(true);
}
