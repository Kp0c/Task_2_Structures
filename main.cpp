#include "main.h"

void PrintAnyType(const any_type::AnyType& anyType)
{
	std::cout << "Type: " << anyType.GetType() << std::endl;
	std::cout << "Value: " << anyType << std::endl;
}

int main()
{
    any_type::AnyType a = 2;
    any_type::AnyType b = 3.7;

	std::swap(a, b);
    /*try
	{
		a/=b;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
    }*/
	PrintAnyType(a);
	PrintAnyType(b);
	std::swap(a, b);
	PrintAnyType(a);
    PrintAnyType(b);

    /*try
	{
	double stored = a.GetDouble();
	a += 5.6;

	a.Destroy();

	a = 'a';
	std::cout << a << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
    }*/
	return 0;
}
