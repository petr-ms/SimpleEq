#include <iostream>
#include <locale>

#include "SeParser.h"

using namespace std;

SeParser::SeParser()
{
	this->decimalSeparator = '.';
	this->parsingExpression = "";
	this->parsingExpressionLength = 0;
	this->ptr = 0;
	this->currentChar = 0;
}


SeParser::~SeParser()
{
}

void SeParser::ShowMessage()
{
	cout << "Show message from parser!";
}

void SeParser::Parse(string expString)
{
	getNextToken();
}

SeParserTokenModel* SeParser::getNextToken()
{	
	if (currentChar >= '0' && currentChar <= '9')
		return parseDecimalNumber();

	if (currentChar >= 'a' && currentChar <= 'z' || currentChar >= 'A' && currentChar <= 'Z')
		return parseIdentifier();


	return nullptr;
}

SeParserTokenModel* SeParser::parseDecimalNumber()
{
	double value = 0;
	auto divider = 0;

	while (true)
	{
		auto numb = currentChar - '0';

		if (divider == 0)
		{
			value = value * 10 + numb;
		}
		else
		{
			value = value + numb / divider;
			divider *= 10;
		}

		ptr++;
		currentChar = this->parsingExpression[ptr];
		if (currentChar >= '0' && currentChar <= '9')
			continue;

		if (currentChar == this->decimalSeparator)
		{
			divider = 10;
			ptr++;
			currentChar = parsingExpression[ptr];
			continue;
		}

		break;
	}

	SeParserTokenModel* resToken = new SeParserTokenInstance<double>(DECIMAL_NUMBER, value);
	return resToken;
}

SeParserTokenModel* SeParser::parseIdentifier()
{
	string value = "";
	while (true)
	{
		value = value + currentChar;
		ptr++;
		currentChar = this->parsingExpression[ptr];
		
		if (currentChar >= 'a' && currentChar <= 'z' || currentChar >= 'A' && currentChar <= 'Z')
		{
			continue;
		}

		break;
	}

	SeParserTokenModel* resToken = new SeParserTokenInstance<string>(IDENTIFIER, value);
	return resToken;
}