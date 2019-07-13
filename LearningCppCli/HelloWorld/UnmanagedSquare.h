#pragma once
class UnmanagedSquare
{
private:
	double side;
public:
	UnmanagedSquare(double);
	double CalculateArea();
	virtual ~UnmanagedSquare();
};

