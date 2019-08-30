#pragma once

/*
	In C++/CLI, a member can be overridden in two ways:
		- override: this polymorphically overrides the base class member
		- new: this hides the base method of the same name

	There are three types of overrides in C++/CLI:
	 - Simple overriding
	 - Renamed (Named) overriding
	 - Multiple overriding
*/

#define SHOW Console::WriteLine(__FUNCTION__)

namespace NewVsOverride
{
	ref class Base
	{
	public:
		virtual void Hello()
		{
			SHOW;
		}

		virtual void Bye()
		{
			SHOW;
		}
	};

	ref class Derived : public Base
	{
	public:
		void Hello() override	// overriding the base class function. This is simple overriding
		{
			SHOW;
		}

		void Bye() new
		{
			SHOW;
		}
	};

	void Demo()
	{
		Base^ obj = gcnew Derived();
		obj->Hello();
		obj->Bye();
	}
}

namespace RenamedOverriding
{
	ref class Base
	{
	public:
		virtual void Hello()
		{
			SHOW;
		}

		virtual void Bye()
		{
			SHOW;
		}
	};

	ref class Derived : Base
	{
	public:
		virtual void SayHello() = Base::Hello
		{
			SHOW;
		}

		void Bye() new
		{
			SHOW;
		}

		virtual void SayBye() = Base::Bye
		{
			SHOW;
		}
	};

	void Demo()
	{
		Base^ obj = gcnew Derived();
		obj->Hello();	// calls Derived::SayHello
		obj->Bye();	// calls Derived::SayBye
	}
}

namespace MultipleOverriding
{
	ref class Base
	{
	public:
		virtual void Hello()
		{
			SHOW;
		}

		virtual void Bye()
		{
			SHOW;
		}
	};

	interface class IInterface
	{
		virtual void Hi();
	};

	ref class Derived : Base, IInterface
	{
	public:
		virtual void SayHello() = Base::Hello, IInterface::Hi	// override multiple methods
		{
			SHOW;
		}
	};

	void Demo()
	{
		Derived derived;
		
		IInterface^ iHnd = % derived;
		Base^ bHnd = % derived;

		// Following two method calls invoke the same method in the derived class
		iHnd->Hi();	// calls Base::SayHello
		bHnd->Hello(); // calls Base::SayHello
	}
}