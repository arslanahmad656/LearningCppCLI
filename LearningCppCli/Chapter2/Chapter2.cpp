// Chapter2.cpp : main project file.

#include "stdafx.h"
#include "Properties.h"
#include "Delegates/Delegates.h"
#include "Events/Intro.h"
#include "Events/Example.h"

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
	EventExample::Demo();

    Console::WriteLine(L"End of program...");
	Console::ReadKey(false);
    return 0;
}
