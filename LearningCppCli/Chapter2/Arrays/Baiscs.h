#pragma once
using namespace System;

namespace SingleDimensionArrays
{
	void Demo()
	{
		array<int>^ arr1 = gcnew array<int>(5);
		for (int i = 0; i < arr1->Length; i++)
		{
			arr1[i] = i * 10;
		}

		array<String^>^ arr2 = gcnew array<String^>
		{
			"Arslan", "Asim", "Usman"
		};

		for (int i = 0; i < arr1->Length; i++)
		{
			Console::WriteLine("Element at {0}: {1}", i, arr1[i]);
		}

		for each (String ^ s in arr2)
		{
			Console::WriteLine("Element: {0}", s);
		}
	}
}

namespace MultiDimensionalArrays
{
	void Demo()
	{
		array<int, 2> ^ matrix = gcnew array<int, 2>(9, 13);
		for (int i = 0; i < matrix->GetLength(0); i++)
		{
			for (int j = 0; j < matrix->GetLength(1); j++)
			{
				matrix[i, j] = i * j + 3;
			}
		}

		for (int i = 0; i < matrix->GetLength(0); i++)
		{
			Console::WriteLine();

			for (int j = 0; j < matrix->GetLength(1); j++)
			{
				Console::Write(" {0, -3}   ", matrix[i, j]);
			}
			Console::WriteLine();
			Console::WriteLine();
		}
	}
}

namespace JaggedArrays
{
	void Demo()
	{
		array<array<String^>^>^ table = gcnew array<array<String^>^>(4);

		array<String^>^ houses = { "Gryffindor", "Slytherin", "Hufflepuff", "Ravenclaw" };

		array<String^>^ gryffindor = { "Harry Potter", "Ron Weasley", "Fred Weasly", "Lavendar Brown" };
		array<String^>^ slytherin = { "Draco Malfoy", "Tom Riddle", "Evan Rosier" };
		array<String^>^ hufflepuff = { "Cedric Diggory", "Hannah Abbot" };
		array<String^>^ ravenclaw = { "Cho Chang" };

		table[0] = gryffindor;
		table[1] = slytherin;
		table[2] = hufflepuff;
		table[3] = ravenclaw;

		for (int i = 0; i < table->Length; i++)
		{
			Console::Write("Students in {0}: ", houses[i]);
			for (int j = 0; j < table[i]->Length; j++)
			{
				Console::Write("{0};  ", table[i][j]);
			}

			Console::WriteLine();
		}
	}
}

namespace ArraysAsFunctionArgs
{
	void InitArray(array<int>^% arr, int size)	// passed by tracking reference
	{
		arr = gcnew array<int>(size);
		for (int i = 0; i < arr->Length; i++)
		{
			arr[i] = i * 13;
		}
	}

	void Demo()
	{
		array<int>^ arr;
		InitArray(arr, 7);
		for each (int item in arr)
		{
			Console::Write("{0}   ", item);
		}
	}
}

namespace ArrayAsReturnTypes
{
	array<int>^ GetInitializedArray(int size)	// passed by tracking reference
	{
		array<int>^ arr = gcnew array<int>(size);
		for (int i = 0; i < arr->Length; i++)
		{
			arr[i] = i * 13;
		}
		return arr;
	}

	void Demo()
	{
		array<int>^ arr = GetInitializedArray(7);
		for each (int item in arr)
		{
			Console::Write("{0}   ", item);
		}
	}
}

namespace ParameterArrays
{
	void PrintNumbers(...array<int>^ numbers)
	{
		if (numbers->Length == 0)
		{
			Console::WriteLine("No numbers received.");
		}
		Console::Write("Numbers received: ");
		for each (int item in numbers)
		{
			Console::Write("{0}  ", item);
		}

		Console::WriteLine();
	}

	void Demo()
	{
		PrintNumbers();
		PrintNumbers(1);
		PrintNumbers(1, 2, 3);
	}
}

namespace MistakeInForeach
{
	void Mistake()
	{
		array<String^>^ strarr = gcnew array<String^>(5);
		int count = 0;
		for each (String ^ s in strarr)
			s = gcnew String(count++.ToString());	// here s is just a local copy of the reference. Hence this local copy of the reference is updated and the original remains intact
		for each (String ^ s in strarr)
			Console::WriteLine(s);
		// Do not expect the output to be 0, 1, 2, 3, 4!!!!
	}

	void Correct()
	{
		array<String^>^ strarr = gcnew array<String^>(5);
		int count = 0;
		for each (String^% s in strarr)
			s = gcnew String(count++.ToString());	// if the reference has to be updated in place, use a tracking reference
		for each (String ^ s in strarr)
			Console::WriteLine(s);
	}

	void Demo()
	{
		Mistake();
		Console::WriteLine();
		Correct();
	}
}

namespace ArrayCovariance
{
	void Demo()
	{
		array<Object^>^ arr = gcnew array<int^>(5);	// array of a parent type can refer to an array of the derived type


		//array<Object^>^ arr = gcnew array<int>(5);	// won't compile because covariance is limited to ref types (or boxed types) only
	}
}

namespace ManagedArrayOfNative
{
	class Native	// a native class
	{
	public:
		Native()
		{
			Console::WriteLine(__FUNCSIG__);
		}

		~Native()
		{
			Console::WriteLine(__FUNCSIG__);
		}
	};

	void Demo()
	{
		// A managed array cannot directly hold the native objects. However, a managed array can hold pointers to native objects
		//array<Native>^ natives;	// compiler error: cannot contain the native types
		
		array<Native*>^ natives = gcnew array<Native*>(5);
		for each (Native*% native in natives)
		{
			native = new Native();
		}

		// a memory leakage would occur if the native objects are not explicitly destroyed before leaving the function
		for each (Native* native in natives)
		{
			delete native;
		}
	}
}

namespace AccessingManagedArraysUsingNativePointers
{
	void Demo()
	{
		array<int>^ arr = { 10, 20, 30, 40, 50 };	// created a managed array
		pin_ptr<int> pinPtr = &arr[0];	// pinned the managed array on the GC heap so that it should not move around during GC. However, it might introduce the heap fragmentation
		int* iteratingPtr = pinPtr;	// stored the address of first element of managed array in a pointer to int
		int* lastAddress = pinPtr + arr->Length;	// stored the address of the last element in another pointer. Note that the + operator here performs the pointer arithematics here.

		while (iteratingPtr < lastAddress)
		{
			(*iteratingPtr)++;	// incremented the value which is placed at this location
			iteratingPtr++;	// moved the pointer to next memory location (again, pointer arithematics i.e., it will be iterated by four bytes which the size of int)
		}

		for each (int item in arr)
		{
			Console::Write("{0}  ", item);
		}
	}
}