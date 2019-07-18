#include "stdafx.h"
#include "ManagedSquare.h"


double ManagedRefSquare::CalculateArea()
{
	return System::Math::Pow(this->side, 2);
}

ManagedRefSquare::ManagedRefSquare(double side)
{
	this->side = side;
}
