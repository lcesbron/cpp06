#include "ScalarConverter.hpp"

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
