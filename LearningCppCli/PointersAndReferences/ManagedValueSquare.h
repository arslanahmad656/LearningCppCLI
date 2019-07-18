#pragma once
value class ManagedValueSquare
{
	// Objects of value classes are not passed by reference. They are passed by reference
private:
	int side;
public:
	ManagedValueSquare(int side);
	void DoubleSide();
	void DisplayArea();
};

