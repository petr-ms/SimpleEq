// SeConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "../SeParser/SeParser.h"

using namespace std;

int main(int argc, _TCHAR* argv[])
{
	string testExpr = "1*x + 10 = 0";
	auto parser = new SeParser();
	//parser->Parse(testExpr);

	return 0;
}

