#pragma once

using namespace System;

ref class R
{
public:
	R()
	{
		Console::WriteLine(__FUNCSIG__);
	}
	~R()
	{
		Console::WriteLine(__FUNCSIG__);
	}
protected:
	!R()
	{
		Console::WriteLine(__FUNCSIG__);
	}
};

namespace DemoCtorFinalizer
{
	void Demo()
	{
		R^ r1 = gcnew R(); // Object r1 created
		R^ r2 = gcnew R(); // Object r2 created
		Console::WriteLine("About to delete r1");
		delete r1; // r1's destructor is invoked
		Console::WriteLine("Exiting function");

		// The finalizer will not be called for r1 since its destructor has been called (after which compiler automatically calls GC::SuppressFinalize(this)
	}
}