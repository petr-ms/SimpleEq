#include "SeParserToken.h"

template SeParserTokenInstance<double>::SeParserTokenInstance(SeParserTokenId tkType, double value);
template SeParserTokenInstance<std::string>::SeParserTokenInstance(SeParserTokenId tkType, std::string value);

SeParserTokenModel::SeParserTokenModel(SeParserTokenId tkType)
{
	this->tokenId = tkType;
}

SeParserTokenModel::~SeParserTokenModel()
{
}

SeParserTokenId SeParserTokenModel::GetTokenId() const
{
	return this->tokenId;
}

template <typename T>
SeParserTokenInstance<T>::SeParserTokenInstance(SeParserTokenId tkType, T value) :SeParserTokenModel(tkType)
{
	this->tokenValue = value;
}

template <typename T>
SeParserTokenInstance<T>::~SeParserTokenInstance()
{
}

template <typename T>
T SeParserTokenInstance<T>::GetValue() const
{
	return this->tokenValue;
}