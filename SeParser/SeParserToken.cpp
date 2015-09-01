#include "SeParserToken.h"


SeParserToken::SeParserToken(SeParserTokenId tkType)
{
	tokenType = tkType;
}

SeParserToken::~SeParserToken()
{
}

SeParserTokenId SeParserToken::GetTokenId() const
{
	return tokenType;
}

SeParserDecimalNumberToken::SeParserDecimalNumberToken(SeParserTokenId tkType, double value) : SeParserToken(tkType)
{
	dValue = value;
}

SeParserDecimalNumberToken::~SeParserDecimalNumberToken()
{
}

double SeParserDecimalNumberToken::GetValue() const
{
	return this->dValue;
}

SeParserIdentifierToken::SeParserIdentifierToken(SeParserTokenId tkType, std::string value) :SeParserToken(tkType)
{
	this->sValue = value;
}

SeParserIdentifierToken::~SeParserIdentifierToken()
{
}

std::string SeParserIdentifierToken::GetValue() const
{
	return this->sValue;
}