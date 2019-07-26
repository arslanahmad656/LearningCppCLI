#pragma once

using namespace System;

ref class RefClassStudent
{
private:
	String^ name;
	int rollNumber;
public:
	RefClassStudent(String^ name, int rollNumber)
		: name(name), rollNumber(rollNumber)
	{
		// empty body
	}

	String^ GetStudentInfo()
	{
		return String::Format("{0} - {1}", this->name, this->rollNumber);
	}
};

