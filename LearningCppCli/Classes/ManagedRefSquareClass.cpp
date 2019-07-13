#include "stdafx.h"
#include "ManagedRefSquareClass.h"



ManagedRefSquareClass::ManagedRefSquareClass(int size) : size(new int(size))
{
	std::cout << "ManagedRefSquareClass constructor" << std::endl;
}

ManagedRefSquareClass::~ManagedRefSquareClass()
{
	std::cout << "ManagedRefSquareClass destructor" << std::endl;
	this->!ManagedRefSquareClass();
}

ManagedRefSquareClass::!ManagedRefSquareClass()
{
	std::cout << "ManagedRefSquareClass finalizer" << std::endl;
	delete size;
}

void ManagedRefSquareClass::CalculateArea()
{
	std::cout << "ManagedRefSquareClass Area" << System::Math::Pow(*size, 2) << std::endl;
}
