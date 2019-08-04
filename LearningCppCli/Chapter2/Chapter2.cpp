// Chapter2.cpp : main project file.

#include "stdafx.h"
#include "Properties.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	Properties::DemoSimpleProperties();

    Console::WriteLine(L"End of program...");
	Console::ReadKey(false);
    return 0;
}
