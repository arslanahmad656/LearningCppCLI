#pragma once
ref class BaseCourse
{
public:
	ref struct CourseData
	{
		int courseCode;
		CourseData(int code)
		{
			courseCode = code;
		}
	};

private:
	CourseData^ courseData;

public:
	BaseCourse(int code) : courseData(gcnew CourseData(code))
	{
	}

	virtual property CourseData^ Data	// virutal property which means that the accessors are virtual
	{
		CourseData^ get()
		{
			return courseData;
		}

		void set(CourseData^ value)
		{
			courseData->courseCode = value->courseCode;
		}
	}

	virtual void Print()
	{
		Console::WriteLine("Course code: {0}", this->Data->courseCode);
	}
};

