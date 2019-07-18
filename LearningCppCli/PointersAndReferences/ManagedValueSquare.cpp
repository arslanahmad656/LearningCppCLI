#include "pch.h"
#include "ManagedValueSquare.h"

ManagedValueSquare::ManagedValueSquare(int side) : side(side)
{
	
}

void ManagedValueSquare::DoubleSide()
{
	this->side *= 2;
}

void ManagedValueSquare::DisplayArea()
{
	std::cout << "Area of managed value square: " << std::pow(this->side, 2) << std::endl;
}
