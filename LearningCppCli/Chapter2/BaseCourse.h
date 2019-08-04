#pragma once
ref class BaseCourse
{
public:
	value struct CourseData
	{
		int courseCode;
		CourseData(int code)
		{
			courseCode = code;
		}
	};

private:
	CourseData courseData;

public:
	BaseCourse() : BaseCourse(CourseData())
	{
		// delegated to another ctor
	}

	BaseCourse(CourseData data) : courseData(data)
	{
		// empty
	}

	virtual property CourseData Data	// virutal property which means that the accessors are virtual
	{
		CourseData get()
		{
			return courseData;
		}

		void set(CourseData value)
		{
			courseData.courseCode = value.courseCode;
		}
	}
};

