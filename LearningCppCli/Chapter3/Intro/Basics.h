#pragma once

using namespace System;

/*

	The C++/CLI compiler follows the following rules for implementing stack semantics:
	 - If a class has either a destructor or a finalizer, the compiler generates a void Dispose(bool) method which calls:
		- destructor if it is called with a true argument
		- finalizer if it is called with a false argument
	- If a class has a destructor, the compiler makes the class implement System::Disposable interface and generates the void System::IDisposable::Dispose() method.
	  This method calls Dispose(true) which in turn calls the destructor. After then, it calls GC::SuppressFinalize(this) so that the object should be removed from the finalization queue because the object needs not be finalized now that its destructor has been called.
	- If a class has a finalizer, the compiler makes the class override System::Object::Finalize method which calls the Dispose(false) which in turn calls the finalizer of the class.

	The compiler follows the above mentioned rules because, the .NET does not directly support the deterministic destruction.
*/

// Consider the given class:

ref class UserWrittenClass
{
public:
	~UserWrittenClass()
	{
		// User code here
	}

	!UserWrittenClass()
	{
		// user code here
	}
};

// The above class will be translated in to the equivalent of the following class by the compiler

ref class CompilerTransformedClass : IDisposable
{
private:	// the user defined destructor and finalizer are moved to a private block
	~CompilerTransformedClass()
	{
		// user written code
	}

	!CompilerTransformedClass()
	{
		// user written code
	}

protected:
	/*void Dispose(bool disposing)	// compiler automatically generates these. User cannot define these functions
	{
		if (disposing)
		{
			~CompilerTransformedClass();
		}
		else 
		{
			!CompilerTransformedClass();
		}
	}

	void Finalize()
	{
		Dispose(false);
	}*/

public:
	virtual void Dispse()
	{
		//Dispose(true);	// compiler calls this method
		GC::SuppressFinalize(this);
	}
};
