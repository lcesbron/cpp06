#include "ScalarConverter.hpp"
#include <iostream>
#include <ostream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string const& toConvert)
{
	e_types				type;
	s_value				val;

	type = determineType(toConvert);
	val = computeValue(toConvert, type);
	printValues(val);
}
