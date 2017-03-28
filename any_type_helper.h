#pragma once
#include <utility>
#include <exception>
#include <cmath>

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

//custom operators
//disable warnings about some bad operations, because it's up to user
#pragma warning(push)
#pragma warning(disable:4800) //bool
#pragma warning(disable:4804) //bool
#pragma warning(disable:4244) //compiler thinks that there bad conversation
							  //(Modulo with floating points)

struct Plus
{
	template<class T, class U>
	T operator()(T& lhs, U& rhs) const
	{
		return lhs + rhs;
	}
};

struct Minus
{
	template<class T, class U>
	T operator()(T& lhs, U& rhs) const
	{
		return lhs - rhs;
	}
};

struct Multiplication
{
	template<class T, class U>
	T operator()(T& lhs, U& rhs) const
	{
		return lhs * rhs;
	}
};

struct Divide
{
	template<class T, class U>
	T operator()(T& lhs, U& rhs) const
	{
		return lhs / rhs;
	}
};

struct Modulo
{
	//regular % operation for integral types
	template<class T, class U>
	typename std::enable_if<std::is_integral<T>::value, T>::type operator()(T& lhs, U& rhs) const
	{
		return lhs % rhs;
	}

	//special mod from <cmath> for floating point types
	template<class T, class U>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type
	operator() (T& lhs, U& rhs) const
	{
		const std::type_info& type_id = typeid(T);

		if (type_id == typeid(float))
			return fmodf(lhs, rhs);
		else if (type_id == typeid(double))
			return fmod(lhs, rhs);
		else if (type_id == typeid(long double))
			return fmodl(lhs, rhs);
		else
			throw std::invalid_argument("floating in modulo");
	}
};

struct Bitwise_and
{
	//Regular & operation for integral types
	template<class T, class U>
	typename std::enable_if<std::is_integral<T>::value, T>::type operator()(T& lhs, U& rhs) const
	{
		return lhs & rhs;
	}

	//Bad operation for floating point types
	template<class T, class U>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T, U) const
	{
		throw std::invalid_argument("floating point in Bitwise_and");
	}
};

struct Bitwise_or
{
	//Regular | operation for integral types
	template<class T, class U>
	typename std::enable_if<std::is_integral<T>::value, T>::type operator()(T& lhs, U& rhs) const
	{
		return lhs | rhs;
	}

	//Bad operation for floating point types
	template<class T, class U>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T, U) const
	{
		throw std::invalid_argument("floating in Bitwise_or");
	}
};

struct Bitwise_xor
{
	//Regular ^ operation for integral types
	template< class T, class U>
	typename std::enable_if<std::is_integral<T>::value, T>::type operator()(T& lhs, U& rhs) const
	{
		return lhs ^ rhs;
	}

	//Bad operation for floating point types
	template<class T, class U>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T, U) const
	{
		throw std::invalid_argument("floating in Bitwise_xor");
	}
};

struct Bitwise_right_shift
{
	//Regular >> operation for integral types
	template< class T, class U>
	typename std::enable_if<std::is_integral<T>::value, T>::type operator()(T& lhs, U& rhs) const
	{
		return lhs >> rhs;
	}

	//Bad operation for floating point types
	template<class T, class U>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T, U) const
	{
		throw std::invalid_argument("floating in Bitwise_right_shift");
	}
};

struct Bitwise_left_shift
{
	//Regular << operation for integral types
	template< class T, class U>
	typename std::enable_if<std::is_integral<T>::value, T>::type operator()(T& lhs, U& rhs) const
	{
		return lhs << rhs;
	}

	//Bad operation for floating point types
	template<class T, class U>
	typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T, U) const
	{
		throw std::invalid_argument("floating in Bitwise_left_shift");
	}
};
//enable warnings back, bad section is behind.
#pragma warning(pop)

}
