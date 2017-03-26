#include "anytype.h"

//disable warnings about some bad operations, because it's up to user
#pragma warning(disable:4800)
#pragma warning(disable:4804)

//using here, it's don't pollute global scope :)
using namespace any_type_helper;

namespace any_type
{

template<typename T>
T AnyType::doOperationForIntegers(T a, T b, OperationType operation) const
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
		return a / b;
		break;
	case OperationType::MODULO:
		return a % b;
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
T AnyType::doOperationForRational(T a, T b, OperationType operation) const
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
		return a / b;
		break;
	default:
		throw std::invalid_argument("bad operation");
		break;
	}
}

AnyType AnyType::doOperation(const AnyType& a, const AnyType& b, OperationType operation) const
{
	if(isTypesMatch(a, b))
	{
		AnyType to_return(0);
		to_return.selected_type = a.selected_type;

		switch (this->selected_type)
		{
		case Type::BOOL:
			to_return = doOperationForIntegers<bool>(a.value.b, b.value.b, operation);
			break;
		case Type::CHAR:
			to_return = doOperationForIntegers<char>(a.value.c, b.value.c, operation);
			break;
		case Type::UCHAR:
			to_return = doOperationForIntegers<unsigned char>(a.value.uc, b.value.uc, operation);
			break;
		case Type::WCHAR_T:
			to_return = doOperationForIntegers<wchar_t>(a.value.wc_t, b.value.wc_t, operation);
			break;
		case Type::SHORT:
			to_return = doOperationForIntegers<short>(a.value.s, b.value.s, operation);
			break;
		case Type::USHORT:
			to_return = doOperationForIntegers<unsigned short>(a.value.us, b.value.us, operation);
			break;
		case Type::INT:
			to_return = doOperationForIntegers<int>(a.value.i, b.value.i, operation);
			break;
		case Type::UINT:
			to_return = doOperationForIntegers<unsigned int>(a.value.ui, b.value.ui, operation);
			break;
		case Type::LONG:
			to_return = doOperationForIntegers<long>(a.value.l, b.value.l, operation);
			break;
		case Type::ULONG:
			to_return = doOperationForIntegers<unsigned long>(a.value.ul, b.value.ul, operation);
			break;
		case Type::LONG_LONG:
			to_return = doOperationForIntegers<long long>(a.value.ll, b.value.ll, operation);
			break;
		case Type::ULONG_LONG:
			to_return = doOperationForIntegers<unsigned long long>(a.value.ull, b.value.ull, operation);
			break;
		case Type::FLOAT:
			to_return = doOperationForRational<float>(a.value.f, b.value.f, operation);
			break;
		case Type::DOUBLE:
			to_return = doOperationForRational<double>(a.value.d, b.value.d, operation);
			break;
		case Type::LONG_DOUBLE:
			to_return = doOperationForRational<long double>(a.value.ld, b.value.l, operation);
			break;
		default:
			throw std::invalid_argument("undefined type");
			break;
		}

		return to_return;
	}
	else
	{
		throw std::invalid_argument("types doesn't match");
	}
}

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

bool AnyType::GetBool() const
{
	if(isTypesMatch(selected_type,Type::BOOL))
		return value.b;
	else
		throw std::bad_cast();
}

char AnyType::GetChar() const
{
	if(isTypesMatch(selected_type,Type::CHAR))
		return value.c;
	else
		throw std::bad_cast();
}

unsigned char AnyType::GetUnsignedChar() const
{
	if(isTypesMatch(selected_type,Type::UCHAR))
		return value.uc;
	else
		throw std::bad_cast();
}

wchar_t AnyType::GetWChar_t() const
{
	if(isTypesMatch(selected_type,Type::WCHAR_T))
		return value.wc_t;
	else
		throw std::bad_cast();
}

short AnyType::GetShort() const
{
	if(isTypesMatch(selected_type,Type::SHORT))
		return value.s;
	else
		throw std::bad_cast();
}

unsigned short AnyType::GetUnsignedShort() const
{
	if(isTypesMatch(selected_type,Type::USHORT))
		return value.us;
	else
		throw std::bad_cast();
}

int AnyType::GetInt() const
{
	if(isTypesMatch(selected_type,Type::INT))
		return value.i;
	else
		throw std::bad_cast();
}

unsigned int AnyType::GetUnsignedInt() const
{
	if(isTypesMatch(selected_type,Type::UINT))
		return value.ui;
	else
		throw std::bad_cast();
}

long AnyType::GetLongInt() const
{
	if(isTypesMatch(selected_type,Type::LONG))
		return value.l;
	else
		throw std::bad_cast();
}

unsigned long AnyType::GetUnsignedLongInt() const
{
	if(isTypesMatch(selected_type,Type::ULONG))
		return value.ul;
	else
		throw std::bad_cast();
}

long long AnyType::GetLongLongInt() const
{
	if(isTypesMatch(selected_type,Type::LONG_LONG))
		return value.ll;
	else
		throw std::bad_cast();
}

unsigned long long AnyType::GetUnsignedLongLongInt() const
{
	if(isTypesMatch(selected_type,Type::ULONG_LONG))
		return value.ull;
	else
		throw std::bad_cast();
}

float AnyType::GetFloat() const
{
	if(isTypesMatch(selected_type,Type::FLOAT))
		return value.f;
	else
		throw std::bad_cast();
}

double AnyType::GetDouble() const
{
	if(isTypesMatch(selected_type,Type::DOUBLE))
		return value.d;
	else
		throw std::bad_cast();
}

long double AnyType::GetLongDouble() const
{
	if(isTypesMatch(selected_type,Type::LONG_DOUBLE))
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

AnyType AnyType::operator+(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::PLUS);
}

AnyType AnyType::operator-(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::MINUS);
}

AnyType AnyType::operator*(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::MULTIPLICATION);
}

AnyType AnyType::operator/(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::DIVIDE);
}

AnyType AnyType::operator%(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::MODULO);
}

AnyType AnyType::operator&(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::BITWISE_AND);
}

AnyType AnyType::operator|(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::BITWISE_OR);
}

AnyType AnyType::operator^(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::BITWISE_XOR);
}

AnyType AnyType::operator>>(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::BITWISE_RIGHT_SHIFT);
}

AnyType AnyType::operator<<(const AnyType& right) const
{
	return doOperation(*this, right, OperationType::BITWISE_LEFT_SHIFT);
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

std::ostream& operator<<(std::ostream& o, const AnyType& obj)
{
	switch (obj.selected_type)
	{
	case Type::BOOL:
		o << obj.value.b;
		break;
	case Type::CHAR:
		o << obj.value.c;
		break;
	case Type::UCHAR:
		o << obj.value.uc;
		break;
	case Type::WCHAR_T:
		o << obj.value.wc_t;
		break;
	case Type::SHORT:
		o << obj.value.s;
		break;
	case Type::USHORT:
		o << obj.value.us;
		break;
	case Type::INT:
		o << obj.value.i;
		break;
	case Type::UINT:
		o << obj.value.ui;
		break;
	case Type::LONG:
		o << obj.value.l;
		break;
	case Type::ULONG:
		o << obj.value.ul;
		break;
	case Type::LONG_LONG:
		o << obj.value.ll;
		break;
	case Type::ULONG_LONG:
		o << obj.value.ull;
		break;
	case Type::FLOAT:
		o << obj.value.f;
		break;
	case Type::DOUBLE:
		o << obj.value.d;
		break;
	case Type::LONG_DOUBLE:
		o << obj.value.ld;
		break;
	default:
		throw std::invalid_argument("Bad type");
		break;
	}

	return o;
}

void swap(AnyType& a, AnyType& b)
{
	using std::swap;
	swap(a.value, b.value);
	swap(a.selected_type, b.selected_type);
}

} //any_type
