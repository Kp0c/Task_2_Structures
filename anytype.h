#pragma once

#include <ostream>
#include <exception>

#include "any_type_helper.h"

namespace any_type
{

class AnyType
{
public:
	//Constructors area
	AnyType(bool value);
	AnyType(char value);
	AnyType(unsigned char value);
	AnyType(wchar_t value);
	AnyType(short value);
	AnyType(unsigned short value);
	AnyType(int value);
	AnyType(unsigned int value);
	AnyType(long int value);
	AnyType(unsigned long int value);
	AnyType(long long int value);
	AnyType(unsigned long long int value);
	AnyType(float value);
	AnyType(double value);
	AnyType(long double value);

	//Copy ctor
	AnyType(const AnyType& another);
	//Move ctor
	AnyType(AnyType&& another);

	inline void Destroy()
	{
		value.ll = 0;
		selected_type = any_type_helper::Type::NONE;
	}


	//Operators overload area
	AnyType operator+(const AnyType& right) const;
	AnyType operator-(const AnyType& right) const;
	AnyType operator*(const AnyType& right) const;
	AnyType operator/(const AnyType& right) const;
	AnyType operator%(const AnyType& right) const;
	AnyType operator&(const AnyType& right) const;
	AnyType operator|(const AnyType& right) const;
	AnyType operator^(const AnyType& right) const;
	AnyType operator<<(const AnyType& right) const;
	AnyType operator>>(const AnyType& right) const;

	//Assignment operators
	AnyType& operator=(const AnyType& right);
	AnyType& operator+=(const AnyType& right);
	AnyType& operator-=(const AnyType& right);
	AnyType& operator*=(const AnyType& right);
	AnyType& operator/=(const AnyType& right);
	AnyType& operator%=(const AnyType& right);
	AnyType& operator&=(const AnyType& right);
	AnyType& operator|=(const AnyType& right);
	AnyType& operator^=(const AnyType& right);
	AnyType& operator<<=(const AnyType& right);
	AnyType& operator>>=(const AnyType& right);

	//move assignment operator
	AnyType& operator=(AnyType&& right);

	//geters
	bool GetBool() const;
	char GetChar() const;
	unsigned char GetUnsignedChar() const;
	wchar_t GetWChar_t() const;
	short GetShort() const;
	unsigned short GetUnsignedShort() const;
	int GetInt() const;
	unsigned int GetUnsignedInt() const;
	long int GetLongInt() const;
	unsigned long int GetUnsignedLongInt() const;
	long long int GetLongLongInt() const;
	unsigned long long int GetUnsignedLongLongInt() const;
	float GetFloat() const;
	double GetDouble() const;
	long double GetLongDouble() const;
	std::string GetType() const;

	//friends
	friend std::ostream& operator<<(std::ostream& o, const AnyType& obj);

private:
	static inline bool IsTypesMatch(const AnyType& a, const AnyType& b)
	{
		return IsTypesMatch(a.selected_type, b.selected_type);
	}

	static inline bool IsTypesMatch(any_type_helper::Type a, any_type_helper::Type b)
	{
		return a == b;
	}

	template<class Operation>
	AnyType ChooseAndDoOperation(const AnyType& a, const AnyType& b, const Operation& op) const
	{
		if (IsTypesMatch(a, b))
		{
			switch (this->selected_type)
			{
			case Type::BOOL:
				return AnyType(op(a.value.b, b.value.b));
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

	any_type_helper::AnyValue value;
	any_type_helper::Type selected_type;
};

}
