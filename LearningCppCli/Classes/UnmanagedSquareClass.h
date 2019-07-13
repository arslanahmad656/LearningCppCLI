#pragma once
class UnmanagedSquareClass
{
private:
	int* side;
public:
	UnmanagedSquareClass(int side);
	void DisplayArea();
	~UnmanagedSquareClass();
	//!UnmanagedSquareClass();	// cannot create a finalizer here. Finalizer can only be created in a managed class
};

