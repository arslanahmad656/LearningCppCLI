#include "pch.h"
#include "ManagedRefSquare.h"

using namespace System;

ManagedRefSquare::ManagedRefSquare(int side) : side(side)
{

}

ManagedRefSquare::~ManagedRefSquare()
{
	Console::WriteLine(L"ManagedRefSquare destructor");
	this->!ManagedRefSquare();
}

ManagedRefSquare::!ManagedRefSquare()
{
	Console::WriteLine(L"ManagedRefSquare finalizer");
}

void ManagedRefSquare::DoubleSide()
{
	this->side *= 2;
}

void ManagedRefSquare::DisplayArea()
{
	std::cout << "Area of managed square: " << std::pow(this->side, 2) << std::endl;
}
