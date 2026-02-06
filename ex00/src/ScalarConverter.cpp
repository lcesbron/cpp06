#include "ScalarConverter.hpp"
#include <iostream>

void	ScalarConverter::convert(std::string const& toConvert)
{
	e_types				type;
	u_value				val;

	type = determineType(toConvert);
	if (type == INT)
		std::cout << "INT" << std::endl;
	else if (type == DOUBLE)
		std::cout << "DOUBLE" << std::endl;
	else if (type == CHAR)
		std::cout << "CHAR" << std::endl;
	else if (type == FLOAT)
		std::cout << "FLOAT" << std::endl;
	else
		std::cout << type << std::endl;
}
