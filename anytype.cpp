#include "anytype.h"

//using here, it's don't pollute global scope :)
using namespace any_type_helper;

namespace any_type
{

AnyType::AnyType(bool value)
{
	selected_type = Type::BOOL;
	this->value.b = value;
}

AnyType::AnyType(char value)
{
	selected_type = Type::CHAR;
	this->value.c = value;
}

AnyType::AnyType(unsigned char value)
{
	selected_type = Type::UCHAR;
	this->value.uc = value;
}

AnyType::AnyType(wchar_t value)
{
	selected_type = Type::WCHAR_T;
	this->value.wc_t = value;
}

AnyType::AnyType(short value)
{
	selected_type = Type::SHORT;
	this->value.s = value;
}

AnyType::AnyType(unsigned short value)
{
	selected_type = Type::USHORT;
	this->value.us = value;
}

AnyType::AnyType(int value)
{
	selected_type = Type::INT;
	this->value.i = value;
}

AnyType::AnyType(unsigned int value)
{
	selected_type = Type::UINT;
	this->value.ui = value;
}

AnyType::AnyType(long value)
{
	selected_type = Type::LONG;
	this->value.l = value;
}

AnyType::AnyType(unsigned long value)
{
	selected_type = Type::ULONG;
	this->value.ul = value;
}

AnyType::AnyType(long long value)
{
	selected_type = Type::LONG_LONG;
	this->value.ll = value;
}

AnyType::AnyType(unsigned long long value)
{
	selected_type = Type::ULONG_LONG;
	this->value.ull = value;
}

AnyType::AnyType(float value)
{
	selected_type = Type::FLOAT;
	this->value.f = value;
}

AnyType::AnyType(double value)
{
	selected_type = Type::DOUBLE;
	this->value.d = value;
}

AnyType::AnyType(long double value)
{
	selected_type = Type::LONG_DOUBLE;
	this->value.ld = value;
}

AnyType::AnyType(const AnyType& another)
{
	this->selected_type = another.selected_type;
	this->value = another.value;
}

AnyType::AnyType(AnyType&& another)
{
	this->selected_type = std::move(another.selected_type);
	this->value = std::move(another.value);
}

AnyType AnyType::operator+(const AnyType& right) const
{
    return ChooseAndDoOperation(*this, right, Plus());
}

AnyType AnyType::operator-(const AnyType& right) const
{
    return ChooseAndDoOperation(*this, right, Minus());
}

AnyType AnyType::operator*(const AnyType& right) const
{
    return ChooseAndDoOperation(*this, right, Multiplication());
}

AnyType AnyType::operator/(const AnyType& right) const
{
    return ChooseAndDoOperation(*this, right, Divide());
}

AnyType AnyType::operator%(const AnyType& right) const
{
    return ChooseAndDoOperation(*this, right, Modulo());
}

AnyType AnyType::operator&(const AnyType& right) const
{
    return ChooseAndDoOperation(*this, right, Bitwise_and());
}

AnyType AnyType::operator|(const AnyType& right) const
{
    return ChooseAndDoOperation(*this, right, Bitwise_or());
}

AnyType AnyType::operator^(const AnyType& right) const
{
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

AnyType& AnyType::operator= (const AnyType& right)
{
	this->selected_type = right.selected_type;
	this->value = right.value;
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
	this->selected_type = std::move(right.selected_type);
	this->value = std::move(right.value);

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
	default:
		throw std::invalid_argument("Bad type");
		break;
	}

	return output;
}

//disable warnings about some bad operations, because it's up to user
#pragma warning(push)
#pragma warning(disable:4800)
#pragma warning(disable:4804)

/*template<typename T, class Operation>
    typename std::enable_if<std::is_integral<T>::value, T>::type
        DoOperation(T a, T b, Operation operation)
{
    switch (operation)
	{
	case OperationType::PLUS:
		return a + b;
		break;
	case OperationType::MINUS:
		return a - b;
		break;
	case OperationType::MULTIPLICATION:
		return a * b;
		break;
	case OperationType::DIVIDE:
		if (b!=0)
			return a / b;
		else
			throw std::overflow_error("Divide by zero");
		break;
	case OperationType::MODULO:
		if (b!=0)
			return a % b;
		else
			throw std::overflow_error("Modulo by zero");
		break;
	case OperationType::BITWISE_AND:
		return a & b;
		break;
	case OperationType::BITWISE_OR:
		return a | b;
		break;
	case OperationType::BITWISE_XOR:
		return a ^ b;
		break;
	case OperationType::BITWISE_LEFT_SHIFT:
		return a << b;
		break;
	case OperationType::BITWISE_RIGHT_SHIFT:
		return a >> b;
		break;
	default:
		throw std::invalid_argument("bad operation");
		break;
    }
}

template<typename T>
    typename std::enable_if<std::is_floating_point<T>::value, T>::type
        DoOperation(T a, T b, OperationType operation)
{
    switch (operation) {
	case OperationType::PLUS:
		return a + b;
		break;
	case OperationType::MINUS:
		return a - b;
		break;
	case OperationType::MULTIPLICATION:
		return a * b;
		break;
	case OperationType::DIVIDE:
		if (b!=0)
			return a / b;
		else
			throw std::overflow_error("Divide by zero");
		break;
	default:
		throw std::invalid_argument("bad operation");
		break;
    }
}*/

template<class Operation>
AnyType AnyType::ChooseAndDoOperation(const AnyType& a, const AnyType& b, const Operation& op) const
{
	if (IsTypesMatch(a, b))
    {
        switch (this->selected_type)
		{
		case Type::BOOL:
            return AnyType(op(a.value.b,b.value.b));
            break;
        case Type::CHAR:
            return AnyType(op(a.value.c, b.value.c));
            break;
        case Type::UCHAR:
            return AnyType(op(a.value.uc, b.value.uc));
            break;
        case Type::WCHAR_T:
            return AnyType(op(a.value.wc_t, b.value.wc_t));
            break;
        case Type::SHORT:
            return AnyType(op(a.value.s, b.value.s));
            break;
        case Type::USHORT:
            return AnyType(op(a.value.us, b.value.us));
            break;
        case Type::INT:
            return AnyType(op(a.value.i, b.value.i));
            break;
        case Type::UINT:
            return AnyType(op(a.value.ui, b.value.ui));
            break;
        case Type::LONG:
            return AnyType(op(a.value.l, b.value.l));
            break;
        case Type::ULONG:
            return AnyType(op(a.value.ul, b.value.ul));
            break;
        case Type::LONG_LONG:
            return AnyType(op(a.value.ll, b.value.ll));
            break;
        case Type::ULONG_LONG:
            return AnyType(op(a.value.ull, b.value.ull));
            break;
            //TODO: fix it :)
        case Type::FLOAT:
            return AnyType(op(a.value.f, b.value.f));
            break;
        case Type::DOUBLE:
            return AnyType(op(a.value.d, b.value.d));
            break;
        case Type::LONG_DOUBLE:
            return AnyType(op(a.value.ld, b.value.l));
            break;
		default:
			throw std::invalid_argument("undefined type");
			break;
        }
	}
	else
	{
		throw std::invalid_argument("types doesn't match");
	}
}

//enable warnings back, bad section is behind.
#pragma warning(pop)

} //any_type
