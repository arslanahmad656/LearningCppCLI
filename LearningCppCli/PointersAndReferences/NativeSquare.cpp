#include "pch.h"
#include "NativeSquare.h"

NativeSquare::NativeSquare(int side) : side(side)
{

}

void NativeSquare::DisplayArea()
{
	std::cout << "Area of native square: " << std::pow(this->side, 2) << std::endl;
}
