#pragma once

using namespace System;

ref class RefClassStudent
{
private:
	String^ name;
	int rollNumber;
	void Copy(RefClassStudent^ copy)
	{
		this->name = copy->name;
		this->rollNumber = copy->rollNumber;
	}
public:
	RefClassStudent(String^ name, int rollNumber)
		: name(name), rollNumber(rollNumber)
	{
		// empty body
	}

	RefClassStudent(RefClassStudent^ copy) // this is the standard copy ctor
	{
		Copy(copy);
	}

	RefClassStudent(RefClassStudent% copy)	// non-standard version just for convenience in case of stack semantics
	{
		Copy(% copy);
	}

	String^ GetStudentInfo()
	{
		return String::Format("{0} - {1}", this->name, this->rollNumber);
	}
};

