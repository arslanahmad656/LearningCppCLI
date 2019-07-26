// compile this class using CL /CLR /LD

#pragma once

#pragma comment(lib, "Advapi32")

#include <windows.h>
#include <lmcons.h>

using namespace System;

class UsernameInfo
{
public:
	String^ GetUserInfo()
	{
		TCHAR buffer[UNLEN + 1];
		DWORD length = UNLEN + 1;

		GetUserName(buffer, &length);

		String^ username = gcnew String(buffer);
		return username;
	}
};

