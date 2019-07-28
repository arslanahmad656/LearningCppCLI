// Boxing.cpp : main project file.

#include "stdafx.h"
#include <iostream>

using namespace System;

namespace BoxingUnboxing 
{
	void DemoBoxingUnboxing()
	{
		int i = 100;	// declared an integer
		Object^ boxed_i = i;	// boxing is implicit value type int32 is automatically boxed in to Object type
		int j = *safe_cast<int^>(boxed_i); // unboxing

		// above unboxing can be simply written as:
		int k = (int)boxed_i;
	}

	void DemoBoxingUnboxingDifferentValues()
	{
		int i = 100;
		Int32^ boxed_i = i;	// this is different entity from i
		boxed_i = (int)boxed_i - 1;	// changed the value of boxed int
		int unboxed_i = (int)boxed_i;
		unboxed_i = unboxed_i - 10;

		Console::WriteLine("Original i: {0}", i);
		Console::WriteLine("Boxed i: {0}", boxed_i);
		Console::WriteLine("Unboxed i: {0}", unboxed_i);
	}

	void TypeSafety()
	{
		int i = 100;
		double d = 3.14159;

		Object^ boxed_int = i;
		Object^ boxed_double = d;

		try
		{
			double unboxed_d = (double)boxed_int;
		}
		catch (InvalidCastException^ e)
		{
			Console::WriteLine("Error: {0}", e->Message);
		}

		try
		{
			int unboxed_i = *safe_cast<int^>(boxed_double);
		}
		catch (InvalidCastException^ e)
		{
			Console::WriteLine("Error: {0}", e->Message);
		}
	}

	void AssigningNull()
	{
		int^ x = 0;	// invalid way to set null! Here x has handle to boxed int whose value is 0
		if (!x)	// this won't execute since x has a non-null handle
		{
			Console::WriteLine("x is null");
		}
		else 
		{
			Console::WriteLine("X is not null. Its value is {0}", x);
		}

		x = nullptr;	// correct way to store null in a handle
		if (!x)	// this will execute since x has a null handle
		{
			Console::WriteLine("x is null");
		}
		else
		{
			Console::WriteLine("X is not null. Its value is {0}", x);
		}
	}
}

namespace Overloads
{
	void ShowInt(int x)
	{
		Console::WriteLine(__FUNCSIG__);
	}

	void ShowInt(int^ x)
	{
		Console::WriteLine(__FUNCSIG__);
	}

	void DemoOverload()
	{
		// the boxing overload take the least priority!
		// If an int is passed and a cast has to be performed, boxing cast takes the least priority

		int x = 32;	
		int^ obj = 11;

		ShowInt(x);	// version taking int will be called
		ShowInt(obj);	// version taking int^ will be called
	}
}

namespace Overloads2
{
	void ShowInt(double x)
	{
		Console::WriteLine(__FUNCSIG__);
	}

	void ShowInt(int^ x)
	{
		Console::WriteLine(__FUNCSIG__);
	}

	void DemoOverload()
	{
		// the boxing overload take the least priority!
		// If an int is passed and a cast has to be performed, boxing cast takes the least priority

		int x = 32;
		int^ obj = 11;

		ShowInt(x);	// version taking double will be called
		ShowInt(obj);	// version taking int^ will be called
	}
}

namespace Overloads3
{
	void ShowInt(double x)
	{
		Console::WriteLine(__FUNCSIG__);
	}

	void ShowInt(double^ x)
	{
		Console::WriteLine(__FUNCSIG__);
	}

	void DemoOverload()
	{
		// the boxing overload take the least priority!
		// If an int is passed and a cast has to be performed, boxing cast takes the least priority

		int x = 32;
		int^ obj = 11;

		ShowInt(x);	// version taking double will be called
		//ShowInt(obj);	// compilation error: no overload can be found
	}
}


int main(array<System::String ^> ^args)
{
	//BoxingUnboxing::DemoBoxingUnboxing();
	//BoxingUnboxing::DemoBoxingUnboxingDifferentValues();
	//BoxingUnboxing::TypeSafety();
	//BoxingUnboxing::AssigningNull();

	//Overloads::DemoOverload();
	Overloads2::DemoOverload();

	system("pause");
    return 0;
}
