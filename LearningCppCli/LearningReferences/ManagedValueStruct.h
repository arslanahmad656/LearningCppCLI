#pragma once
value struct ManagedValueStruct
{
private:
	int value;

public:
	ManagedValueStruct(int value) : value(value)
	{

	}

	void DisplayValue()
	{
		System::Console::WriteLine(value);
	}
};

