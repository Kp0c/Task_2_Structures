#pragma once

namespace any_type_helper
{

enum class Type
{
	BOOL,
	CHAR,
	UCHAR,
	WCHAR_T,
	SHORT,
	USHORT,
	INT,
	UINT,
	LONG,
	ULONG,
	LONG_LONG,
	ULONG_LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE,
	NONE
};

enum class OperationType
{
	PLUS,
	MINUS,
	MULTIPLICATION,
	DIVIDE,
	MODULO,
	BITWISE_AND,
	BITWISE_OR,
	BITWISE_XOR,
	BITWISE_LEFT_SHIFT,
	BITWISE_RIGHT_SHIFT
};

union AnyValue
{
	bool b;
	char c;
	unsigned char uc;
	wchar_t wc_t;
	short s;
	unsigned short us;
	int i;
	unsigned int ui;
	long int l;
	unsigned long int ul;
	long long int ll;
	unsigned long long int ull;
	float f;
	double d;
	long double ld;
};

}
