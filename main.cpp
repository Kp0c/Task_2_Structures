#include <main.h>
#include <iostream>

int main()
{
	any_type::AnyType a = 1;
	a = true;
	a = 1.7;
	try
	{
		int stored = a.GetInt();
	}
	catch(std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	double stored = a.GetDouble();

	std::cout << a << std::endl;
	return 0;
}
