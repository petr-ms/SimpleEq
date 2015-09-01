#pragma once
#include <string>

//#include "Platform.h"

enum SeParserTokenId
{
	ADDITION_OPERATOR = 0,
	SUBTRACTION_OPERATOR = 1,
	MULTIPLICATION_OPERATOR = 2,
	DIVISION_OPERATOR = 3,
	POWER_OPERATOR = 4,
	GT = 5,
	LT = 6,
	GE = 7,
	LE = 8,
	EQ = 9,
	VARIABLE = 10,
	FUNCTION = 11,
	DECIMAL_NUMBER = 12
};

class SeParserToken
{
public:
	explicit SeParserToken(SeParserTokenId tkType);
	virtual ~SeParserToken();

	SeParserTokenId GetTokenId() const;
private:
	SeParserTokenId tokenType;
	std::string tokenValue;

};

class SeParserDecimalNumberToken : public SeParserToken
{
public:
	explicit SeParserDecimalNumberToken(SeParserTokenId tkType, double value);
	~SeParserDecimalNumberToken();

	double GetValue() const;
private:
	double dValue;
};

class SeParserIdentifierToken : public SeParserToken
{
public:
	explicit SeParserIdentifierToken(SeParserTokenId tkType, std::string value);
	~SeParserIdentifierToken();

	std::string GetValue() const;
private:
	std::string sValue;
};


