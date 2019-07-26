#include "pch.h"
#include "RefClassStudent.h"
#include "ValueStructStudent.h"

using namespace System;

namespace SimpleInitializations
{
	void InitValueType()
	{
		/*
			Following student is created on stack. The identifier student contains the value of student.
			In this example, gcnew is compiled to IL newobj instruction since it is used to instantiate
			a ref type objec.t
		*/
		ValueStructStudent studentOnStacked("Arslan", 2012068);

		/*
			Following student is created on heap. The object is first created on stack, then it is boxed 
			and moved to the heap and its handle is stored in the identifier studentOnHeap.
			In this example, gcnew compiles to IL initobj instruction since it is used to instantiate a 
			value type object.
		*/
		ValueStructStudent^ studentOnHeap = gcnew ValueStructStudent("Asim", 142918);
	}

	void InitRefType()
	{
		/*
			Following student seems to have been created on the stack; it is NOT created on stack! It's created
			on heap but is only used like a stack allocated object. (A special syntax determinitically invoke
			the destruction).
		*/
		RefClassStudent studentStack("Usman", 565);

		/*
			Following object is created on heap. Note that the identifier directly refers to the object (not
			to the boxed version of the object).
		*/
		RefClassStudent^ studentHeap = gcnew RefClassStudent("Zaid", 555);
	}
}

namespace CopyConstructors
{
	void CopyValue()
	{
		/*
			Value types provide default copy constructors. These types do not allow providing a custom implementation
			of copy constructor. Value types are copied bitwise.
		*/

		/*
			Following demonstrates the copy by value on stack
		*/
		ValueStructStudent studentOnStacked("Arslan", 2012068);
		ValueStructStudent studentOnStackCopy(studentOnStacked);	// default copy constructor

		/*
			Following example is illegal
		*/
		//ValueStructStudent^ studentOnHeap = gcnew ValueStructStudent("Asim", 456);
		//ValueStructStudent^ studentOnHeapCopy = gcnew ValueStructStudent(*studentOnHeap);	// not allowed
		//bool heapTestResult = studentOnHeap == studentOnHeapCopy;
	}

	void CopyRef()
	{
		/*
			Ref types do not provide the default copy constructors. Copy copy constructor has to be provided 
			in order to enable the copy semantics.
		*/

		{
			/*
				Following example shows how to copy using stack semantics
			*/
			RefClassStudent studentStack("Arslan", 2012068);
			RefClassStudent studentStackCopy(studentStack);	// using non standard version of copy
			RefClassStudent studentStackCopy2(% studentStack);	// standard version of copy ctor
		}

		{
			/*
			Following example demonstrates how to copy using heap semantics.
			NOTE THAT: The three objects are equivalent but not the same objects.
			A copy of studentHeap is created and the handle of the copied
			object is stored in studentHeapCopy and studentHeapCopy2 identifiers. In other words, all of these
			identifiers point to two different objects.
		*/
			RefClassStudent^ studentHeap = gcnew RefClassStudent("Asim", 456);
			RefClassStudent^ studentHeapCopy = gcnew RefClassStudent(studentHeap);	 // standard version of copy
			RefClassStudent^ studentHeapCopy2 = gcnew RefClassStudent(*studentHeap);	// non-standard version of copy

			// The equality operator on the handles checks the equality of the references
			bool result = studentHeap == studentHeapCopy;	// false
			result = studentHeap == studentHeapCopy2;	// false
			result = studentHeapCopy == studentHeapCopy2;	// false
		}
	}
}

int main(array<System::String ^> ^args)
{
	/*{
		SimpleInitializations::InitValueType();
		SimpleInitializations::InitRefType();
	}*/

	{
		CopyConstructors::CopyValue();
		CopyConstructors::CopyRef();
	}
    return 0;
}
