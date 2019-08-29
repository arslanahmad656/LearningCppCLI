// Chapter2.cpp : main project file.

#include "stdafx.h"
#include "Properties.h"
#include "Delegates/Delegates.h"
#include "Events/Intro.h"
#include "Events/Example.h"
#include "Arrays/Baiscs.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	// PROPERTIES
	//Properties::DemoSimpleProperties();
	//Properties::DemoInheritedProperties();
	//Properties::DemoStaticProperties();

	// DELEGATES
	//DelegatesSynchronous::DemoStatic();
	//DelegatesSynchronous::DemoInstance();
	//DelegatesSynchronous::DemoChain();
	//DelegatesAsynchronous::DemoAsync();

	// EVENTS
	//DemoSimpleEvents::Demo();
	//EventExample::Demo();

	//ARRAYS
	//SingleDimensionArrays::Demo();
	//MultiDimensionalArrays::Demo();
	//JaggedArrays::Demo();
	//ArraysAsFunctionArgs::Demo();
	//ArrayAsReturnTypes::Demo();
	//ParameterArrays::Demo();
	//MistakeInForeach::Demo();
	//ArrayCovariance::Demo();
	//ManagedArrayOfNative::Demo();
	AccessingManagedArraysUsingNativePointers::Demo();

    Console::WriteLine(L"End of program...");
	Console::ReadKey(false);
    return 0;
}
