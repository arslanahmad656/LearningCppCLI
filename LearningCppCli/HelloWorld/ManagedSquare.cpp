#include "stdafx.h"
#include "ManagedSquare.h"


double ManagedSquare::CalculateArea()
{
	return System::Math::Pow(this->side, 2);
}

ManagedSquare::ManagedSquare(double side)
{
	this->side = side;
}
