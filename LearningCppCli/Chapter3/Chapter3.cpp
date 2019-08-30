#include "pch.h"
#include "Intro/Example.h"
#include "StackSemantics/Intro.h"
#include "FunctionOverriding/Overriding.h"

using namespace System;

int main(array<System::String ^> ^args)
{
	// INTRO
	//DemoCtorFinalizer::Demo();

	// USING STACK SEMANTICS
	//WithoutUsingStackSemantics::Demo();
	//UsingStackSemantics::Demo();
	//StackSemanticsForMemberObjects::Demo();

	// FUNCTION OVERRIDING
	//NewVsOverride::Demo();
	//RenamedOverriding::Demo();
	MultipleOverriding::Demo();

    return 0;
}
