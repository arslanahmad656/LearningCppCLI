#pragma once
using namespace System;

delegate void NumberHandler(int);

ref class RandomNumberGenerator
{
private:
	Random^ random;
	int start;
	int end;
public:
	event NumberHandler^ OnDivisibleBySeven;
	event NumberHandler^ OnDivisibleByThree;

	RandomNumberGenerator(int start, int end)
		: random(gcnew Random()),
		start(start),
		end(end)
	{
		// empty
	}

	void GenerateNumbers()
	{
		for (int i = start; i < end; i++)
		{
			ProcessEvents(i);
		}
	}

	void ProcessEvents(int num)
	{
		if (num % 7 == 0)
		{
			OnDivisibleBySeven(num);
		}
		
		if (num % 3 == 0)
		{
			OnDivisibleByThree(num);
		}
	}
};

namespace DemoSimpleEvents
{
	void DivisbleByThreeHandler(int num)
	{
		Console::WriteLine("Divisible by 3: {0}", num);
	}

	void DivisbleBySevenHandler(int num)
	{
		Console::WriteLine("Divisible by 7: {0}", num);
	}

	void Demo()
	{
		RandomNumberGenerator^ rnd = gcnew RandomNumberGenerator(1, 100);
		rnd->OnDivisibleBySeven += gcnew NumberHandler(&DivisbleBySevenHandler);
		rnd->OnDivisibleByThree += gcnew NumberHandler(&DivisbleByThreeHandler);

		rnd->GenerateNumbers();
	}
}