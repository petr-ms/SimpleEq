#pragma once

//#include "Platform.h"
#include <string>

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
	IDENTIFIER = 10,
	FUNCTION = 11,
	DECIMAL_NUMBER = 12
};


class SeParserTokenModel
{
public:
	explicit SeParserTokenModel(SeParserTokenId tkType);
	virtual ~SeParserTokenModel();

	SeParserTokenId GetTokenId() const;

private:
	SeParserTokenId tokenId;
};


template <typename T> class SeParserTokenInstance : public SeParserTokenModel
{
public:
	//template<typename T>
	explicit SeParserTokenInstance(SeParserTokenId tkType, T value);
	virtual ~SeParserTokenInstance() override;

	T GetValue() const;
private:
	T tokenValue;
};


//template class SeParserTokenInstance<double>;
//template class SeParserTokenInstance<std::string>;



