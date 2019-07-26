#include "pch.h"
#include <iostream>

using namespace System;

void TestNativePointersAndReferences()
{
	int x = 10;
	int* xPtr = &x;
	int& xRef = x;

	int** xxPtr = &xPtr;	// pointer to pointer
	std::cout << "Value of x: " << *(*xxPtr) << std::endl;

	//int&* xRefPtr = &xRef;	// pointer to reference is not allowed

	int*& xRefPtr = xPtr;	// reference to a pointer
}

void TestTrackingHandles() 
{
	int x = 10;
	int^ xHnd = x;
	int% xRef = x;

	int%% xxdcfds = xRef;
	int^% xHndRef = xHnd;
}

int main(array<System::String ^> ^args)
{
	TestNativePointersAndReferences();
    return 0;
}
