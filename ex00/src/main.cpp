#include "ScalarConverter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "./scalar <value_to_convert>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
}
