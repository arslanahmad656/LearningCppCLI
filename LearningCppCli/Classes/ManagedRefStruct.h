#pragma once

#include "stdafx.h"

// Value structs behave like classes in C# and can have default constructors, destructors and finalizers

ref struct ManagedRefSquareStruct
{
private:
	int size;
public:
	ManagedRefSquareStruct();
	~ManagedRefSquareStruct();
	!ManagedRefSquareStruct();
};
