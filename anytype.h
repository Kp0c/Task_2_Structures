#pragma once

#include <ostream>
#include <exception>
#include "any_type_helper.h"

namespace any_type
{

class AnyType
{
private:
	static inline bool isTypesMatch(const AnyType& a, const AnyType& b)
	{
		if (a.selected_type == b.selected_type)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	static inline bool isTypesMatch(any_type_helper::Type a, any_type_helper::Type b)
	{
		if (a == b)
		{
			return true;
		}
		else
		{
			throw std::bad_cast();
		}
	}

	template<typename T>
	T doOperationForIntegers(T a, T b, any_type_helper::OperationType operation) const;
	template<typename T>
	T doOperationForRational(T a, T b, any_type_helper::OperationType operation) const;
	AnyType doOperation(const AnyType& a, const AnyType& b, any_type_helper::OperationType operation) const;

	any_type_helper::AnyValue value;
	any_type_helper::Type selected_type;
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

	inline void Destroy()
	{
		value.i = 0;
		selected_type = any_type_helper::Type::NONE;
	}

	inline void swap(AnyType& another)
	{
		using std::swap;

		swap(value, another.value);
		swap(selected_type, another.selected_type);
	}

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

	//Operators overload area
	AnyType operator +(const AnyType& right) const;
	AnyType operator -(const AnyType& right) const;
	AnyType operator *(const AnyType& right) const;
	AnyType operator /(const AnyType& right) const;
	AnyType operator %(const AnyType& right) const;
	AnyType operator &(const AnyType& right) const;
	AnyType operator |(const AnyType& right) const;
	AnyType operator ^(const AnyType& right) const;
	AnyType operator <<(const AnyType& right) const;
	AnyType operator >>(const AnyType& right) const;
	//Assignment operators
	AnyType& operator= (const AnyType& right);
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
	//Output operator
	friend std::ostream& operator<<(std::ostream& o, const AnyType& obj);
};

}
