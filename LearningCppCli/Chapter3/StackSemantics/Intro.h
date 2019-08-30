#pragma once

using namespace System;
using namespace System::IO;

namespace WithoutUsingStackSemantics
{
	void Demo()
	{
		StreamReader^ r1 = nullptr;
		StreamReader^ r2 = nullptr;
		StreamWriter^ sw = nullptr;

		try
		{
			String^ path1 = Path::Combine(Environment::CurrentDirectory, "file1.txt");
			String^ path2 = Path::Combine(Environment::CurrentDirectory, "file2.txt");
			String^ path3 = Path::Combine(Environment::CurrentDirectory, "file3.txt");
			
			r1 = gcnew StreamReader(path1);
			r2 = gcnew StreamReader(path2);
			sw = gcnew StreamWriter(path3, false);

			String^ text1 = r1->ReadToEnd();
			String^ text2 = r2->ReadToEnd();
			
			for each (char ch in text1)
			{
				sw->Write(ch);
			}

			for each (char ch in text2)
			{
				sw->Write(ch);
			}
		}
		catch (Exception^ ex)
		{
			Console::WriteLine(ex->Message);
		}
		finally
		{
			// delete calls the Dispose of its operand
			delete r1;
			delete r2;
			delete sw;
		}
	}
}

namespace UsingStackSemantics
{
	void Demo()
	{
		String^ path1 = Path::Combine(Environment::CurrentDirectory, "file1.txt");
		String^ path2 = Path::Combine(Environment::CurrentDirectory, "file2.txt");
		String^ path3 = Path::Combine(Environment::CurrentDirectory, "file3.txt");

		// declaring using stack semantics (but it does not mean that the objects are created on stack, these are still created on heap)
		StreamReader r1(path1);
		StreamReader r2(path2);
		StreamWriter sw(path3);

		String^ text1 = r1.ReadToEnd();
		String^ text2 = r2.ReadToEnd();

		for each (char ch in text1)
		{
			sw.Write(ch);
		}

		for each (char ch in text2)
		{
			sw.Write(ch);
		}

		// no delete required because when objects are created on heap using stack semantics, the destructor is automatically called once the objects go out of scope.
	}
}