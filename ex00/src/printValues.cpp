#include "ScalarConverter.hpp"
#include <iostream>

static void	printFromChar(char c)
{
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << static_cast<int>(c) << std::endl;
	std::cout << "float : " << static_cast<float>(c) << std::endl;
	std::cout << "double : " << static_cast<double>(c) << std::endl;
}

void	printValues(s_value val, e_types type)
{
	char	c;
	int		i;
	float	f;
	double	d;


	if (type == CHAR)
	{

	}
	else if (type == INT)
	{

	}
	else if (type >= FLOAT && type < DOUBLE)
	{

	}
	else if (type >= DOUBLE && type)
}
