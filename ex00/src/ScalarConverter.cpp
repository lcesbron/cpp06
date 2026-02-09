#include "ScalarConverter.hpp"
#include <iostream>
#include <ostream>

void	ScalarConverter::convert(std::string const& toConvert)
{
	e_types				type;
	s_value				val;

	type = determineType(toConvert);
	val = computeValue(toConvert, type);
	if (val.overflow)
	{
		std::cout << "overflow" << std::endl;
		return ;
	}
	switch (type)
	{
		case CHAR:
			std::cout << val.val.c << std::endl;
			break ;
		case INT:
			std::cout << val.val.i << std::endl;
			break ;
		case FLOAT:
			std::cout << val.val.f << std::endl;
			break ;
		case DOUBLE:
			std::cout << val.val.d << std::endl;
			break ;
		case DOUBLE_PINF:
			std::cout << val.val.d << std::endl;
			break ;
		case DOUBLE_MINF:
			std::cout << val.val.d << std::endl;
			break ;
		default:
			break ;
	}
	//if (type == INT)
	//	std::cout << "INT" << std::endl;
	//else if (type == DOUBLE)
	//	std::cout << "DOUBLE" << std::endl;
	//else if (type == CHAR)
	//	std::cout << "CHAR" << std::endl;
	//else if (type == FLOAT)
	//	std::cout << "FLOAT" << std::endl;
	//else
	//	std::cout << type << std::endl;
}
