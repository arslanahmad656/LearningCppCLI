#pragma once
using namespace System;
using namespace System::Collections::Generic;

generic<typename T> ref class MyList
{
private:
	List<T>^ list;
public:
	MyList() : list(gcnew List<T>())
	{
		// empty
	}

	void Add(T item)
	{
		list->Add(item);
	}

	bool Remove(T item)
	{
		return list->Remove(item);
	}

	void Print()
	{
		Console::WriteLine();
		for each (T item in list)
		{
			Console::Write("{0}  ", item);
		}
		Console::WriteLine();
	}
};

namespace GenericsIntro
{
	generic<typename T> void PrintLists(...array<MyList<T>^>^ lists)
	{
		for each (MyList<T> ^ list in lists)
		{
			list->Print();
		}
	}

	void Demo()
	{
		MyList<int>^ intList = gcnew MyList<int>();
		intList->Add(1);
		intList->Add(10);
		intList->Add(100);

		MyList<String^>^ strList = gcnew MyList<String^>();
		strList->Add("One");
		strList->Add("Ten");
		strList->Add("Hundred");

		intList->Print();
		strList->Print();

		PrintLists(intList, intList);
	}
}