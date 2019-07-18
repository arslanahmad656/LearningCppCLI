#include "pch.h"
#include "NativeSquare.h"
#include "ManagedRefSquare.h"
#include "ManagedValueSquare.h"

using namespace System;

namespace Driver
{
	void NativeByValue(NativeSquare sq);
	void NativeByReference(NativeSquare& sq);
	void NativeByPointer(NativeSquare* sq);
	void ManagedByValue(ManagedRefSquare sq);
	void ManagedByRef(ManagedRefSquare^ sq);
	void ManagedValueByValue(ManagedValueSquare sq);
	void ManagedValueByReferenceWrong(ManagedValueSquare^ sq);
	void ManagedValueByReferenceCorrect(ManagedValueSquare% sq);

	void DemoUnmanagedPointers()
	{
		// native pointers are just like same as they are for native C++

		NativeSquare sq(5);
		std::cout << "Created native square inside driver function. Square located at: " << &sq << std::endl;
		std::cout << std::endl;

		std::cout << "Pass by value:" << std::endl;
		std::cout << "Before calling, area: ";
		sq.DisplayArea();
		std::cout << std::endl;
		NativeByValue(sq);	// passing native object by value
		std::cout << "After calling, area: ";
		sq.DisplayArea();

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Pass by reference:" << std::endl;
		std::cout << "Before calling, area: ";
		sq.DisplayArea();
		std::cout << std::endl;
		NativeByReference(sq);	// passing native object by ref
		std::cout << "After calling, area: ";
		sq.DisplayArea();

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Pass by pointers:" << std::endl;
		std::cout << "Before calling, area: ";
		sq.DisplayArea();
		std::cout << std::endl;
		NativeByPointer(&sq);	// passing native object by pointer
		std::cout << "After calling, area: ";
		sq.DisplayArea();
	}

	void DemoManagedPointers()
	{
		ManagedRefSquare refSq(15);	// this object is not created on stack! It's on heap. It's just a syntax equivalent using or try/finally blocks in C#
		Console::WriteLine(String::Format(L"Created managed ref square inside driver function. Square located at: {0}", %refSq));
		Console::WriteLine();

		//ManagedByValue(refSq);	// ref classes cannot be passed by value. However, value classes can be passed by value

		std::cout << "Pass by pointers:" << std::endl;
		std::cout << "Before calling, area: ";
		refSq.DisplayArea();
		std::cout << std::endl;
		ManagedByRef(%refSq);	// Passing by reference. Managed objects use % verses & for native.
		std::cout << "After calling, area: ";
		refSq.DisplayArea();
	}

	void DemoManagedPointersByValue()
	{
		ManagedValueSquare sq(10);	// this object is created on stack
		Console::WriteLine(String::Format(L"Created managed ref square inside driver function. Square located at: {0}", %sq));
		Console::WriteLine();


		std::cout << "Pass by Value:" << std::endl;
		std::cout << "Before calling, area: ";
		sq.DisplayArea();
		std::cout << std::endl;
		ManagedValueByValue(sq);	// passing managed object by value. This is possible because this object is instantiated from a value class
		std::cout << "After calling, area: ";
		sq.DisplayArea();

		std::cout << std::endl;
		std::cout << std::endl;

		std::cout << "Pass by reference (wrong way):" << std::endl;
		std::cout << "Before calling, area: ";
		sq.DisplayArea();
		std::cout << std::endl;
		ManagedValueByReferenceWrong(sq);	// passing by reference. But it will be passed by value
		std::cout << "After calling, area: ";
		sq.DisplayArea();

		std::cout << "Pass by reference (correct way):" << std::endl;
		std::cout << "Before calling, area: ";
		sq.DisplayArea();
		std::cout << std::endl;
		ManagedValueByReferenceCorrect(sq);	// passing by reference. But it will be passed by value
		std::cout << "After calling, area: ";
		sq.DisplayArea();
	}

	void NativeByValue(NativeSquare sq)
	{
		std::cout << "Method native by value." << std::endl
			<< "In this function, square is preset at: " << &sq << std::endl
			<< "Value of side is changed." << std::endl;
		sq.DoubleSide();
		std::cout << "Area inside function: ";
		sq.DisplayArea();
	}

	void NativeByReference(NativeSquare& sq)
	{
		std::cout << "Method native by reference." << std::endl
			<< "In this function, square is preset at: " << &sq << std::endl
			<< "Value of side is changed." << std::endl;
		sq.DoubleSide();
		std::cout << "Area inside function: ";
		sq.DisplayArea();
	}

	void NativeByPointer(NativeSquare* sq)
	{
		std::cout << "Method native by pointer." << std::endl
			<< "In this function, square is preset at: " << sq << std::endl
			<< "Value of side is changed." << std::endl;
		sq->DoubleSide();
		std::cout << "Area inside function: ";
		sq->DisplayArea();
	}

	void ManagedByValue(ManagedRefSquare sq)	// how to use this function? Can it ever be used?? Since ref classes cannot be passed as value
	{
		Console::WriteLine(L"Method Managed by value.");
		Console::WriteLine(String::Format(L"In this function, square is preset at: {0}", % sq));
		Console::WriteLine(L"Value of side is changed.");

		sq.DoubleSide();
		std::cout << "Area inside function: ";
		sq.DisplayArea();
	}

	void ManagedByRef(ManagedRefSquare^ sq)
	{
		Console::WriteLine(L"Method Managed by reference.");
		Console::WriteLine(String::Format(L"In this function, square is preset at: {0}", sq));
		Console::WriteLine(L"Value of side is changed.");

		sq->DoubleSide();
		std::cout << "Area inside function: ";
		sq->DisplayArea();
	}

	void ManagedValueByValue(ManagedValueSquare sq)
	{
		Console::WriteLine(L"Method ManagedValueByValue.");
		Console::WriteLine(String::Format(L"In this function, square is preset at: {0}", %sq));	// % is the counterpart of & but it does not display the address
		Console::WriteLine(L"Value of side is changed.");

		sq.DoubleSide();
		std::cout << "Area inside function: ";
		sq.DisplayArea();
	}

	void ManagedValueByReferenceWrong(ManagedValueSquare^ sq)
	{
		// but this will be passed by value
		Console::WriteLine(L"Method ManagedValueByReference.");
		Console::WriteLine(String::Format(L"In this function, square is preset at: {0}", sq));
		Console::WriteLine(L"Value of side is changed.");

		sq->DoubleSide();
		std::cout << "Area inside function: ";
		sq->DisplayArea();
	}

	void ManagedValueByReferenceCorrect(ManagedValueSquare% sq)
	{
		// but this will be passed by value
		Console::WriteLine(L"Method ManagedValueByReference.");
		Console::WriteLine(String::Format(L"In this function, square is preset at: {0}", sq));
		Console::WriteLine(L"Value of side is changed.");

		sq.DoubleSide();
		std::cout << "Area inside function: ";
		sq.DisplayArea();
	}
}

int main(array<System::String^>^ args)
{
	//Driver::DemoUnmanagedPointers();
	//Driver::DemoManagedPointers();
	Driver::DemoManagedPointersByValue();

	system("pause");
}
