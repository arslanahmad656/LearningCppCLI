#include "stdafx.h"
#include "UnmanagedSquare.h"


UnmanagedSquare::UnmanagedSquare(double side)
{
	this->side = side;
}

double UnmanagedSquare::CalculateArea()
{
	return std::pow(this->side, 2);
}

UnmanagedSquare::~UnmanagedSquare()
{
	std::cout << "Destroying square";
}
