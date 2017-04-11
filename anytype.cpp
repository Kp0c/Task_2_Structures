#include "anytype.h"

//using here, it's don't pollute global scope :)
using namespace any_type_helper;

namespace any_type
{

AnyType::AnyType(bool value) : selected_type(Type::BOOL)
{
	this->value.b = value;
}

AnyType::AnyType(char value) : selected_type(Type::CHAR)
{
	this->value.c = value;
}

AnyType::AnyType(unsigned char value) : selected_type(Type::UCHAR)
{
	this->value.uc = value;
}

AnyType::AnyType(wchar_t value) : selected_type(Type::WCHAR_T)
{
	this->value.wc_t = value;
}

AnyType::AnyType(short value) : selected_type(Type::SHORT)
{
	this->value.s = value;
}

AnyType::AnyType(unsigned short value) : selected_type(Type::USHORT)
{
	this->value.us = value;
}

AnyType::AnyType(int value) : selected_type(Type::INT)
{
	this->value.i = value;
}

AnyType::AnyType(unsigned int value) : selected_type(Type::UINT)
{
	this->value.ui = value;
}

AnyType::AnyType(long value) : selected_type(Type::LONG)
{
	this->value.l = value;
}

AnyType::AnyType(unsigned long value) : selected_type(Type::ULONG)
{
	this->value.ul = value;
}

AnyType::AnyType(long long value) : selected_type(Type::LONG_LONG)
{
	this->value.ll = value;
}

AnyType::AnyType(unsigned long long value) : selected_type(Type::ULONG_LONG)
{
	this->value.ull = value;
}

AnyType::AnyType(float value) : selected_type(Type::FLOAT)
{
	this->value.f = value;
}

AnyType::AnyType(double value) : selected_type(Type::DOUBLE)
{
	this->value.d = value;
}

AnyType::AnyType(long double value) : selected_type(Type::LONG_DOUBLE)
{
	this->value.ld = value;
}

AnyType::AnyType(const AnyType& another) : selected_type(another.selected_type)
										 , value(another.value)
{ }

AnyType::AnyType(AnyType&& another)
{
	this->selected_type = std::move(another.selected_type);
	this->value = std::move(another.value);
}

AnyType AnyType::operator+(const AnyType& right) const
{
	return ChooseAndDoOperation(*this, right, std::plus<>());
}

AnyType AnyType::operator-(const AnyType& right) const
{
	return ChooseAndDoOperation(*this, right, std::minus<>());
}

AnyType AnyType::operator*(const AnyType& right) const
{
	return ChooseAndDoOperation(*this, right, std::multiplies<>());
}

AnyType AnyType::operator/(const AnyType& right) const
{
	return ChooseAndDoOperation(*this, right, std::divides<>());
}

AnyType AnyType::operator%(const AnyType& right) const
{
	//i can't use std::modulus, because further there's an be floating type
	return ChooseAndDoOperation(*this, right, Modulo());
}

AnyType AnyType::operator&(const AnyType& right) const
{
	//i can't use std::bit_and, because further there's an be floating type
	return ChooseAndDoOperation(*this, right, Bitwise_and());
}

AnyType AnyType::operator|(const AnyType& right) const
{
	//i can't use std::bit_or, because further there's an be floating type
	return ChooseAndDoOperation(*this, right, Bitwise_or());
}

AnyType AnyType::operator^(const AnyType& right) const
{
	//i can't use std::bit_xor, because further there's an be floating type
	return ChooseAndDoOperation(*this, right, Bitwise_xor());
}

AnyType AnyType::operator>>(const AnyType& right) const
{
	return ChooseAndDoOperation(*this, right, Bitwise_right_shift());
}

AnyType AnyType::operator<<(const AnyType& right) const
{
	return ChooseAndDoOperation(*this, right, Bitwise_left_shift());
}

AnyType& AnyType::operator=(const AnyType& right)
{
	if(&right != this)
	{
		this->selected_type = right.selected_type;
		this->value = right.value;
	}
	return *this;
}

AnyType& AnyType::operator+=(const AnyType& right)
{
	return operator=(operator+(right));
}

AnyType& AnyType::operator-=(const AnyType& right)
{
	return operator=(operator-(right));
}

AnyType& AnyType::operator*=(const AnyType& right)
{
	return operator=(operator*(right));
}

AnyType& AnyType::operator/=(const AnyType& right)
{
	return operator=(operator/(right));
}

AnyType& AnyType::operator%=(const AnyType& right)
{
	return operator=(operator%(right));
}

AnyType& AnyType::operator&=(const AnyType& right)
{
	return operator=(operator&(right));
}

AnyType& AnyType::operator|=(const AnyType& right)
{
	return operator=(operator|(right));
}

AnyType& AnyType::operator^=(const AnyType& right)
{
	return operator=(operator^(right));
}

AnyType& AnyType::operator<<=(const AnyType& right)
{
	return operator=(operator<<(right));
}

AnyType& AnyType::operator>>=(const AnyType& right)
{
	return operator=(operator>>(right));
}

AnyType& AnyType::operator=(AnyType&& right)
{
	if(this != &right)
	{
		this->selected_type = std::move(right.selected_type);
		this->value = std::move(right.value);
	}

	return *this;
}

bool AnyType::GetBool() const
{
	if (IsTypesMatch(selected_type, Type::BOOL))
		return value.b;
	else
		throw std::bad_cast();
}

char AnyType::GetChar() const
{
	if (IsTypesMatch(selected_type, Type::CHAR))
		return value.c;
	else
		throw std::bad_cast();
}

unsigned char AnyType::GetUnsignedChar() const
{
	if (IsTypesMatch(selected_type, Type::UCHAR))
		return value.uc;
	else
		throw std::bad_cast();
}

wchar_t AnyType::GetWChar_t() const
{
	if (IsTypesMatch(selected_type, Type::WCHAR_T))
		return value.wc_t;
	else
		throw std::bad_cast();
}

short AnyType::GetShort() const
{
	if (IsTypesMatch(selected_type, Type::SHORT))
		return value.s;
	else
		throw std::bad_cast();
}

unsigned short AnyType::GetUnsignedShort() const
{
	if (IsTypesMatch(selected_type, Type::USHORT))
		return value.us;
	else
		throw std::bad_cast();
}

int AnyType::GetInt() const
{
	if (IsTypesMatch(selected_type, Type::INT))
		return value.i;
	else
		throw std::bad_cast();
}

unsigned int AnyType::GetUnsignedInt() const
{
	if (IsTypesMatch(selected_type, Type::UINT))
		return value.ui;
	else
		throw std::bad_cast();
}

long AnyType::GetLongInt() const
{
	if (IsTypesMatch(selected_type, Type::LONG))
		return value.l;
	else
		throw std::bad_cast();
}

unsigned long AnyType::GetUnsignedLongInt() const
{
	if (IsTypesMatch(selected_type, Type::ULONG))
		return value.ul;
	else
		throw std::bad_cast();
}

long long AnyType::GetLongLongInt() const
{
	if (IsTypesMatch(selected_type, Type::LONG_LONG))
		return value.ll;
	else
		throw std::bad_cast();
}

unsigned long long AnyType::GetUnsignedLongLongInt() const
{
	if (IsTypesMatch(selected_type, Type::ULONG_LONG))
		return value.ull;
	else
		throw std::bad_cast();
}

float AnyType::GetFloat() const
{
	if (IsTypesMatch(selected_type, Type::FLOAT))
		return value.f;
	else
		throw std::bad_cast();
}

double AnyType::GetDouble() const
{
	if (IsTypesMatch(selected_type, Type::DOUBLE))
		return value.d;
	else
		throw std::bad_cast();
}

long double AnyType::GetLongDouble() const
{
	if (IsTypesMatch(selected_type, Type::LONG_DOUBLE))
		return value.ld;
	else
		throw std::bad_cast();
}

std::string AnyType::GetType() const
{
	std::string type;
	switch (selected_type)
	{
	case Type::BOOL:
		type = "bool";
		break;
	case Type::CHAR:
		type = "char";
		break;
	case Type::UCHAR:
		type = "unsigned char";
		break;
	case Type::WCHAR_T:
		type = "wchar_t";
		break;
	case Type::SHORT:
		type = "short";
		break;
	case Type::USHORT:
		type = "unsigned short";
		break;
	case Type::INT:
		type = "int";
		break;
	case Type::UINT:
		type = "unsigned int";
		break;
	case Type::LONG:
		type = "long int";
		break;
	case Type::ULONG:
		type = "unsigned long int";
		break;
	case Type::LONG_LONG:
		type = "long long int";
		break;
	case Type::ULONG_LONG:
		type = "unsigned long long int";
		break;
	case Type::FLOAT:
		type = "float";
		break;
	case Type::DOUBLE:
		type = "double";
		break;
	case Type::LONG_DOUBLE:
		type = "long double";
		break;
	case Type::NONE:
		type = "empty";
		break;
	default:
		break;
	}
	return type;
}

std::ostream& operator<<(std::ostream& output, const AnyType& obj)
{
	switch (obj.selected_type)
	{
	case Type::BOOL:
		output << obj.value.b;
		break;
	case Type::CHAR:
		output << obj.value.c;
		break;
	case Type::UCHAR:
		output << obj.value.uc;
		break;
	case Type::WCHAR_T:
		output << obj.value.wc_t;
		break;
	case Type::SHORT:
		output << obj.value.s;
		break;
	case Type::USHORT:
		output << obj.value.us;
		break;
	case Type::INT:
		output << obj.value.i;
		break;
	case Type::UINT:
		output << obj.value.ui;
		break;
	case Type::LONG:
		output << obj.value.l;
		break;
	case Type::ULONG:
		output << obj.value.ul;
		break;
	case Type::LONG_LONG:
		output << obj.value.ll;
		break;
	case Type::ULONG_LONG:
		output << obj.value.ull;
		break;
	case Type::FLOAT:
		output << obj.value.f;
		break;
	case Type::DOUBLE:
		output << obj.value.d;
		break;
	case Type::LONG_DOUBLE:
		output << obj.value.ld;
		break;
	case Type::NONE:
		throw std::invalid_argument("Bad type");
	default:
		throw std::invalid_argument("Undefined type");
		break;
	}

	return output;
}

} //any_type
