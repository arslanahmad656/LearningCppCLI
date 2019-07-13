#pragma once

// Value classes behave like structs in C#. They have semantics much like the structs have in C#
// Value classes do not allow destructors or finalizers so these classes should not be used whenever a resource is to be occupied
value class ManagedValueSquareClass
{
private:
	//int* size;	// objects like this should be created in value classes since it becomes difficult to free them.
	int size;
public:
	//ManagedValueSquareClass();	// cannot have default ctors in value classes
	//virtual ~ManagedValueSquareClass();	// cannot have destructors in value classes since these classes are always manipulated by value
	//!ManagedValueSquareClass();	// cannot have finalizers in value classes
	ManagedValueSquareClass(int size);
	void CalculateArea();
};

