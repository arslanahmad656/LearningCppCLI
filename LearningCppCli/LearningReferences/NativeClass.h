#pragma once
class NativeClass
{
private:
	int value;

public:
	NativeClass(int value) : value(value)
	{
	}

	void DisplayValue()
	{
		System::Console::WriteLine(value);
	}
};

