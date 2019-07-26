#include "pch.h"
#include "NativeClass.h"
#include "ManagedValueStruct.h"

using namespace System;

namespace Boxing
{
	NativeClass* BoxingTestNative()
	{
		NativeClass obj(10);
		//return obj;	// not possible (native types are not automatically boxed)
		return nullptr;	// something had to be returned
	}

	ManagedValueStruct^ BoxingTestManaged()
	{
		ManagedValueStruct obj;
		return obj;	// it is possible (managed types are automatically boxed when required)
	}

	NativeClass* BoxingMoveTestNative()
	{
		NativeClass obj(10);	// created an object on the stack
		return &obj;		// returned a pointer to the object created on the stack

		// Caller will get a garbage value since the stack is destroyed
	}

	ManagedValueStruct^ BoxingMoveTestManaged()
	{
		ManagedValueStruct obj(10);	// created an object on the stack
		return obj;	// the value will automatically be boxed.

		// The managed object is copied from stack to heap when it is boxed,
		// hence it will be available to the caller even if the stack would
		// have been destroyed.
	}
}

namespace BoxingUnboxingMore
{
	ref class RefClass{};
	value class ValueClass {};

	void Demo()
	{
		RefClass refClassVal;	// wait! this is not on stack (it is on the heap)
		RefClass^ refClassRef = gcnew RefClass;	// on heap	(this is not a boxed value type)

		ValueClass valueClassVal;	// on stack
		ValueClass^ valueClassRef = gcnew ValueClass;	// on heap (this is a boxed value type)

		// gcnew RefClass is a boxed value, it can be stored in RefClass (after being unboxed)
		//RefClass unboxedRefClass = (RefClass)refClassRef;	// seems like it cannot be unboxed (because refClassRef is not a boxed value)

		// gcnew valueClassRef is  a boxed value:
		ValueClass unboxedValueClass = (ValueClass)valueClassRef;	// success: valueClassRef has been unboxed

		//refClassVal = *refClassRef;	// not possible: without overloaded assignment operator, reference type values cannot be copied
		refClassRef = %refClassVal;	// possible: 
	}
}

namespace DemonstratringDifference
{
	ref class Foo
	{
	public:
		int x = 1;
	};

	void Test(Foo^ temp) 
	{
		temp = gcnew Foo();
		temp->x = 10;
	}

	void Test2(Foo^% temp) 
	{
		temp = gcnew Foo();
		temp->x = 10;
	}

	void Test3(Foo% temp) 
	{
		temp.x = 5;
	}

	void Demo()
	{
		Foo^ f = gcnew Foo();
		Test(f); //f still points to the same Foo, f->x will return 1
		Console::WriteLine("f->x" + f->x);
		Test2(f); //f now points to the new Foo, f->x will return 10
		Console::WriteLine("f->x" + f->x);

		Test(nullptr); //Works fine, but might not be what was intended
		//Test2(nullptr); //ERROR
		Test3(*f); //f->x returns 5 

		Console::WriteLine("f->x" + f->x);
	}
}

namespace StrangeDestructor
{
	ref struct SquareStruct
	{
	public:
		int side;

		SquareStruct(int side) : side(side)
		{

		}

		~SquareStruct()
		{
			side = 0;
		}
	};

	void Demo1(SquareStruct% test)
	{
		// destructor of test will not be called
	}

	SquareStruct^ Demo2()
	{
		SquareStruct square(10);
		Demo1(square);
		Console::WriteLine(square.side);
		return %square;	// square is not de-allocated; however its destructor has been called
	}
}

namespace Vagabond
{
	ref class RefClass {};
	value class ValueClass {};
	class NativeClass {};

	void Test()
	{
		NativeClass* nPtr;
		//RefClass* mPtr;	 // not allowed
		ValueClass* vmPtr;

		ValueClass^ vmHnd;
		//NativeClass^ nHnd;	// not allowed
	}
}

int main(array<System::String ^> ^args)
{
	//NativeClass* nPtr = Boxing::BoxingMoveTestNative();
	//nPtr->DisplayValue();  // will show garbage

	//ManagedValueStruct^ mHnd = Boxing::BoxingMoveTestManaged();
	//mHnd->DisplayValue();	// will show the correct value

	//DemonstratringDifference::Demo();

	StrangeDestructor::SquareStruct^ obj = StrangeDestructor::Demo2();
	Console::WriteLine(obj->side);

    return 0;
}
