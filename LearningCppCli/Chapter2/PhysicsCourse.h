#pragma once
#include "BaseCourse.h"

using namespace System;

ref class PhysicsCourse : public BaseCourse	// inherits from BaseCourse
{
public:
	ref struct PhysicsCourseData : CourseData
	{
		String^ title;

		PhysicsCourseData(String^ title, int code) : CourseData(code)
		{
			this->title = title;
		}
	};

private:
	PhysicsCourseData^ data;

public:
	PhysicsCourse(String^ title, int code) : BaseCourse(code), data(gcnew PhysicsCourseData(title, code))
	{
		// empty
	}

	virtual property CourseData^ Data
	{
		CourseData^ get() override
		{
			return data;
		}

		void set(CourseData^ value) override
		{
			data->courseCode = value->courseCode;
			data->title = safe_cast<PhysicsCourseData^>(value)->title;
		}
	}

	void Print() override
	{
		BaseCourse::Print();
		Console::WriteLine("Course title: {0}", safe_cast<PhysicsCourseData^>(Data)->title);
	}
};

