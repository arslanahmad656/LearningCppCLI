// Classes.cpp : main project file.

#include "stdafx.h"
#include "UnmanagedSquareClass.h"
#include "ManagedRefSquareClass.h"

using namespace System;

namespace Driver
{
	void DemoUnmanagedClass()
	{
		// unmanaged class can be created on stack or on heap. Depending on where it is created, it can be manipulated
		// by value, by pointer or by reference (unmanaged reference)

		{
			UnmanagedSquareClass squareOnStack(10);	// created an object on stack. Here memory management is not an issue because
												// its destructor will automatically be called when the variable goes out of scope.
												// Of course, resource clean-up code needs to be placed in the destructor.
			squareOnStack.DisplayArea();
		} // stack variable will be destroyed here

		UnmanagedSquareClass* squareOnHeap = new UnmanagedSquareClass(15);	// object created on heap and stored in a pointer to its type
		squareOnHeap->DisplayArea();
		delete squareOnHeap;	// this object must be deleted manually before the variable referring to this object goes out of scope
	}

	void DemoManagedRefClassNoDisposing()
	{
		// Managed ref class can only be created on heap and is stored in managed reference (^ operator)
		{
			ManagedRefSquareClass^ squareInInnerScope = gcnew ManagedRefSquareClass(20);
			squareInInnerScope->CalculateArea();
		}
		// the object inside the above block goes out of scope here. Only finalizer is called. Destructor is not called here.
		// So the output properly, invoke this application from command line (if started from visual studio, the finalizer might be called just before the console window is closing)
	}

	void DemoManagedRefClassDisposing()
	{
		// The destructor, if required to be called, must be explicitly called (just like the C# code does not rely on garbage collector to call the Dispose method).
		// In C++/CLI, the finalizer can be called by applying delete operator on the managed class reference.
		ManagedRefSquareClass^ square = gcnew ManagedRefSquareClass(45);
		square->CalculateArea();
		delete square;	// This will call the destructor of the 'square' object.
	}

	void DemoAutomaticDestructorCalling()
	{
		// By default, we never know when or if the destructor would be called. In C# the 'using' and 'try/finally' blocks ensure the calls to the Dispose method when the object goes out of scope.
		// In C++/CLI this mechanism has a different syntax. The object reference is created like an unmanaged object is created on stack. Note, however, that the managed object created like this is never on stack. It's always on heap.
		// What this will do is call the destructor automatically when the object goes out of scope.

		{
			ManagedRefSquareClass square(15);	// this object is NOT created on stack. It is on heap. When this syntax is used, the destructor of this object is automatically called when the object goes out of scope.
			square.CalculateArea();
			//delete square;	// cannot use delete on this object. Actually there is no need to explicitly call the destructor because it will automatically be called anyways.
		}	// destructor called. 'using' or 'try/finally' of C# mechanism acheived
	}
}

int main(array<System::String ^> ^args)
{
	//Driver::DemoUnmanagedClass();
	//Driver::DemoManagedRefClassNoDisposing();
	//Driver::DemoManagedRefClassDisposing();
	Driver::DemoAutomaticDestructorCalling();

	std::cout << "End of progarm...";
	system("pause");
}
