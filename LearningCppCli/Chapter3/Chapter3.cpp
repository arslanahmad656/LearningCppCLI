#include "pch.h"
#include "Intro/Example.h"
#include "StackSemantics/Intro.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	// INTRO
	//DemoCtorFinalizer::Demo();

	// USING STACK SEMANTICS
	//WithoutUsingStackSemantics::Demo();
	UsingStackSemantics::Demo();

    return 0;
}
