#pragma once
ref class ManagedRefSquare
{
	// Objects of ref classes cannot be passed by value. They can only be passed by reference.
	// It seems logical because only those objects can be passed by value that can be created on the stack.
	// Furthermore, there is no such thing as managed pointer, but only managed reference.
private:
	int side;
public:
	ManagedRefSquare(int side);
	~ManagedRefSquare();
	!ManagedRefSquare();
	void DoubleSide();
	void DisplayArea();
};

