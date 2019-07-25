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

int main(array<System::String ^> ^args)
{
	NativeClass* nPtr = Boxing::BoxingMoveTestNative();
	nPtr->DisplayValue();  // will show garbage

	ManagedValueStruct^ mHnd = Boxing::BoxingMoveTestManaged();
	mHnd->DisplayValue();	// will show the correct value

    return 0;
}
