// Compile this file using CL /CLR

#pragma comment(lib, "Advapi32")
#include "pch.h"
#include <Windows.h>
#include <lmcons.h>
#include <iostream>

using namespace System;

int main(array<System::String ^> ^args)
{
	TCHAR usernameBfr[UNLEN + 1];
	DWORD length = UNLEN + 1;

	GetUserName(usernameBfr, &length);

    return 0;
}
