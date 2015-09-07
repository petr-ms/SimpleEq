#pragma once

#include "SeParserToken.h"
#include "Platform.h"

//#include <string>;

class SeParser
{
public:
	ext SeParser();
	ext ~SeParser();
	void ext ShowMessage();
	void ext Parse(std::string);
	
private:
	SeParserTokenModel* getNextToken();
	SeParserTokenModel* parseDecimalNumber();
	SeParserTokenModel* parseIdentifier();

	char decimalSeparator;
	std::string parsingExpression;
	int parsingExpressionLength;
	int ptr;
	char currentChar;
};

