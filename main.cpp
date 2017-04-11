#include "main.h"

void PrintAnyType(const any_type::AnyType& anyType)
{
	std::cout << "Type: " << anyType.GetType() << std::endl;
	std::cout << "Value: " << anyType << std::endl;
}

int main()
{
	any_type::AnyType a = 15.7;
	any_type::AnyType b = 24.3;

	std::cout << a + b << std::endl;
	std::cout << a - b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
	std::cout << b % a << std::endl;
	/*std::cout << b | a << std::endl;
	std::cout << b << a << std::endl;
	std::cout << b >> a << std::endl;*/

	std::swap(a, b);
	try
	{
		a/=b;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	PrintAnyType(a);
	PrintAnyType(b);
	std::swap(a, b);
	PrintAnyType(a);
	PrintAnyType(b);

	try
	{
		double stored = b.GetDouble();
		b += 9.;

		a.Destroy();

		a = 'd';
		std::cout << a << std::endl;
		std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
