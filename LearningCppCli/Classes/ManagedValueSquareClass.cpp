#include "stdafx.h"
#include "ManagedValueSquareClass.h"


ManagedValueSquareClass::ManagedValueSquareClass(int size) : size(size)
{
	std::cout << "ManagedValueSquareClass ctor" << std::endl;
}

void ManagedValueSquareClass::CalculateArea()
{
	std::cout << "ManagedValueSquareClass area: " << std::pow(size, 2) << std::endl;
}
