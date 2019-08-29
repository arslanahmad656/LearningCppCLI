#pragma once
using namespace System;

ref class WordEventArgs : EventArgs
{
public:
	property int Index;
	property String^ Word;
	WordEventArgs(int index, String^ word)
	{
		Index = index;
		Word = word;
	}
};

delegate void WordFoundHanlder(Object^ sender, WordEventArgs^ args);	// .NET style event handler

ref class WordFinder
{
private:
	String^ line;
	WordFoundHanlder^ wordFoundHanlder;
	int handlersCounter;
public:
	WordFinder(String^ line)
		: line(line), wordFoundHanlder(nullptr), handlersCounter(0)
	{
		// empty
	}

	void FindWord(String^ word)
	{
		int lastIndex = -1;
		for each (String^ w in line->Split(' '))
		{
			if (w->Equals(word, StringComparison::InvariantCultureIgnoreCase))
			{
				Object^ sender = this;
				lastIndex = line->IndexOf(word, lastIndex + 1, StringComparison::InvariantCultureIgnoreCase);
				WordEventArgs^ args = gcnew WordEventArgs(lastIndex, w);
				OnWordFound(sender, args);
			}
		}
	}

	event WordFoundHanlder^ OnWordFound
	{
		void add(WordFoundHanlder^ handler)
		{
			if (wordFoundHanlder == nullptr)
			{
				wordFoundHanlder = handler;
			}
			else 
			{
				wordFoundHanlder += handler;
			}

			handlersCounter++;
			Console::WriteLine("Handler attached. Total handlers: {0}", handlersCounter);
		}

		void remove(WordFoundHanlder^ handler)
		{
			if (wordFoundHanlder != nullptr)
			{
				wordFoundHanlder -= handler;
				handlersCounter--;
				Console::WriteLine("Handler removed. Remaining handlers: {0}", handlersCounter);
			}
			else 
			{
				Console::WriteLine("No handler available to remove.");
			}
		}

		void raise(Object^ sender, WordEventArgs^ args)
		{
			if (wordFoundHanlder != nullptr)
			{
				Console::WriteLine("Raising event.");
				wordFoundHanlder->Invoke(sender, args);
			}
			else 
			{
				Console::WriteLine("Cannot raise the event because no handler is attached.");
			}
		}
	}
};

namespace EventExample
{
	void WordFound(Object^ sender, WordEventArgs^ args)
	{
		Console::WriteLine("Word '{0}' found at position {1}", args->Word, args->Index);
	}

	void Demo()
	{
		String^ line = "I felt happy because I saw the others were happy and because I knew I should feel happy, but I wasn’t really happy.";
		WordFinder^ finder = gcnew WordFinder(line);
		finder->OnWordFound += gcnew WordFoundHanlder(&WordFound);
		finder->FindWord("Happy");
	}
}
