#pragma once

using namespace System;

ref class Student
{
private: 
	int age;
public:
	Student()
	{
	}

	property String^ Name;

	property int Age
	{
		int get()
		{
			Console::WriteLine("Getting student age.");
			if (age == 0)
			{
				throw gcnew InvalidOperationException("Cannot access age before initializing it");
			}

			return age;
		}

		void set(int value)
		{
			Console::WriteLine("Setting student age.");
			if (value <= 0)
			{
				throw gcnew ArgumentOutOfRangeException("Age must be at least 1 year");
			}

			this->age = value;
		}
	}
};

