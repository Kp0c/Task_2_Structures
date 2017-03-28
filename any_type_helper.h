#pragma once
#include <utility>
#include <exception>

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

/*enum class OperationType
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
};*/

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

struct Plus
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) + std::forward<U>(rhs))
  { return    std::forward<T>(lhs) + std::forward<U>(rhs); }
};

struct Minus
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) - std::forward<U>(rhs))
  { return    std::forward<T>(lhs) - std::forward<U>(rhs); }
};

struct Multiplication
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) * std::forward<U>(rhs))
  { return    std::forward<T>(lhs) * std::forward<U>(rhs); }
};

struct Divide
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) / std::forward<U>(rhs))
  { return    std::forward<T>(lhs) / std::forward<U>(rhs); }
};

struct Modulo
{
  template<class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) % std::forward<U>(rhs))
  { return    std::forward<T>(lhs) % std::forward<U>(rhs); }

  template<class T, class U>
  typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T,U) const
  {
      throw std::invalid_argument("floating in modulo");
  }
};

struct Bitwise_and
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) & std::forward<U>(rhs))
  { return    std::forward<T>(lhs) & std::forward<U>(rhs); }

  template<class T, class U>
  typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T,U) const
  {
      throw std::invalid_argument("floating in Bitwise_and");
  }
};

struct Bitwise_or
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) | std::forward<U>(rhs))
  { return    std::forward<T>(lhs) | std::forward<U>(rhs); }

  template<class T, class U>
  typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T,U) const
  {
      throw std::invalid_argument("floating in Bitwise_or");
  }
};

struct Bitwise_xor
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) ^ std::forward<U>(rhs))
  { return    std::forward<T>(lhs) ^ std::forward<U>(rhs); }

  template<class T, class U>
  typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T,U) const
  {
      throw std::invalid_argument("floating in Bitwise_xor");
  }
};

struct Bitwise_right_shift
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) >> std::forward<U>(rhs))
  { return    std::forward<T>(lhs) >> std::forward<U>(rhs); }

  template<class T, class U>
  typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T,U) const
  {
      throw std::invalid_argument("floating in Bitwise_right_shift");
  }
};

struct Bitwise_left_shift
{
  template< class T, class U>
  constexpr auto operator()(T&& lhs, U&& rhs) const
  -> decltype(std::forward<T>(lhs) << std::forward<U>(rhs))
  { return    std::forward<T>(lhs) << std::forward<U>(rhs); }

  template<class T, class U>
  typename std::enable_if<std::is_floating_point<T>::value, T>::type operator() (T,U) const
  {
      throw std::invalid_argument("floating in Bitwise_left_shift");
  }
};

}
