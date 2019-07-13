#include "stdafx.h"
#include "UnmanagedSquareClass.h"


UnmanagedSquareClass::UnmanagedSquareClass(int side) : side(new int(side))
{
	std::cout << "UnmanagedSquareClass ctor" << std::endl;
}

void UnmanagedSquareClass::DisplayArea()
{
	std::cout << "Area of UnmanagedSquareClass: " << *side << std::endl;
}


UnmanagedSquareClass::~UnmanagedSquareClass()
{
	delete side;
	std::cout << "UnmanagedSquareClass destructor" << std::endl;
}
