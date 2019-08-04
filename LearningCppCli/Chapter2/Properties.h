#include "stdafx.h"
#include "Student.h"

#ifndef __PROPERTIES__
#define __PROPERTIES__

namespace Properties
{
	void DemoSimpleProperties()
	{
		Student^ student = gcnew Student();

		// Accessing trivial properties:
		// Student::Name is a trivial property in a sense that
		// the compiler automatically generates the minimal getter
		// and setter methods along with the backing store for the
		// Name property.
		student->Name = "Arslan Ahmad";
		Console::WriteLine("Student Name: {0}", student->Name);

		// Access non-trivial properties:
		// Student::Age is a non-trivial property in a sense that
		// we have provided the implementations for its getter 
		// and setter accessors.
		int age;
		try
		{
			age = student->Age;
		}
		catch (Exception^ ex)
		{
			Console::WriteLine(ex->Message);
		}

		student->Age = 10;
		age = student->Age;

		Console::WriteLine("Student age: {0}", age);
	}
}

#endif // !__PROPERTIES__