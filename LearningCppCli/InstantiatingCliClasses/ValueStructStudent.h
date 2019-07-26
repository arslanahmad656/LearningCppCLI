#pragma once

using namespace System;

value struct ValueStructStudent
{
private:
	String^ name;
	int rollNumber;
public:
	ValueStructStudent(String^ name, int rollNumber) 
		: name(name), rollNumber(rollNumber)
	{
		// empty body
	}

	String^ GetStudentInfo()
	{
		return String::Format("{0} - {1}", this->name, this->rollNumber);
	}
};

