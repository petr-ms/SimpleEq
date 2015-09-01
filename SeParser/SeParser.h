#pragma once
#include "Platform.h"
#include "SeParserToken.h"

//#include <string>;

class SeParser
{
public:
	ext SeParser();
	ext ~SeParser();
	void ext ShowMessage();
	void ext Parse(std::string);
	
	SeParserToken getNextToken();
	SeParserToken parseDecimalNumber();
	SeParserToken parseIdentifier();
private:
	char decimalSeparator;
	std::string parsingExpression;
	int parsingExpressionLength;
	int ptr;
	char currentChar;
};

