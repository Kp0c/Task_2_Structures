#include "main.h"

void PrintAnyType(const any_type::AnyType& anyType)
{
	std::cout << "Type: " << anyType.GetType() << std::endl;
	std::cout << "Value: " << anyType << std::endl;
}

int main()
{
    //test<std::plus<void>>();

    //return 0;

    any_type::AnyType a = 2;
    any_type::AnyType b = 6;

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
    //double stored = b.GetDouble();
    b += 9;

	a.Destroy();

    a = 13;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
    }
	return 0;
}
