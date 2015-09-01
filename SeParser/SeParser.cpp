#include <iostream>
#include <locale>

#include "SeParser.h"
#include "SeParserToken.h";


using namespace std;

SeParser::SeParser()
{
	this->decimalSeparator = '.';
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
	auto expLength = expString.length();
	auto ptr = 0;
	
	while (ptr <= expLength)
	{
		auto ch = expString[ptr];
		
		auto inNumber = (ch >= '0' && ch <= '9');
		
		//Number parser
		if (inNumber)
		{
			double value = 0;
			auto divider = 0;

			while (true)
			{
				auto numb = ch - '0';
				
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
				ch = expString[ptr];
				if (ch >= '0' && ch <= '9')
					continue;
				
				if (ch == this->decimalSeparator)
				{
					divider = 10;
					ptr++;
					ch = expString[ptr];
					continue;
				}

				break;
			}
		}
		
		//Variable o function Parser
		if ( ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' )
		{
			
		}

		
	}
}

SeParserToken SeParser::getNextToken()
{	
	if (currentChar >= '0' && currentChar <= '9')
		return parseDecimalNumber();

	if (currentChar >= 'a' && currentChar <= 'z' || currentChar >= 'A' && currentChar <= 'Z')
		return parseIdentifier();
	

}

SeParserToken SeParser::parseDecimalNumber()
{
}

SeParserToken SeParser::parseIdentifier()
{
}