// HelloWorld.cpp : main project file.

#include "stdafx.h"
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	Console::WriteLine(L"Hello managed world");
	std::cout << "Hello unmanaged world" << std::endl;

	Console::ReadKey(true);
}
