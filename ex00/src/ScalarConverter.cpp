#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>
#include <sstream>
#include <ctype.h>
#include <string>
#include <iostream>

enum e_types
{
	NO_TYPE,
	CHAR,
	INT,
	FLOAT,
	FLOAT_PINF,
	FLOAT_MINF,
	FLOAT_NAN,
	DOUBLE,
	DOUBLE_PINF,
	DOUBLE_MINF,
	DOUBLE_NAN,
};

static e_types	determineOneCharType(std::string const& toDet)
{
	if (std::isdigit(toDet[0]))
		return (INT);
	if (std::isprint(toDet[0]))
		return (CHAR);
	return (NO_TYPE);
}

static e_types	determineMultiCharType(std::string const& toDet, size_t toDetSize)
{
	size_t			i;
	size_t			j;
	bool			sign;

	if (toDet == "-inff")
		return (FLOAT_MINF);
	if (toDet == "+inff")
		return (FLOAT_PINF);
	if (toDet == "nanf")
		return (FLOAT_NAN);
	if (toDet == "-inf")
		return (DOUBLE_MINF);
	if (toDet == "+inf")
		return (DOUBLE_PINF);
	if (toDet == "nan")
		return (DOUBLE_NAN);

	if (toDet[0] == '+' || toDet[0] == '-')
	{
		i = 1;
		sign = true;
	}
	else
	{
		i = 0;
		sign = false;
	}
	while (std::isdigit(toDet[i]) && i++ < toDetSize );
	if (toDet[i] == '.')
	{
		++i;
		j = i;
		while (std::isdigit(toDet[i]) && i++ < toDetSize);
		if (i == j)
			return (NO_TYPE);
		if (i == toDetSize)
			return (DOUBLE);
	}
	else if (sign && i == 1)
	{
		return (NO_TYPE);
	}
	else if (i == toDetSize)
		return (INT);
	if (toDet[i] == 'f' && i == toDetSize - 1) // -f case shouldnt work
		return (FLOAT);
	return (NO_TYPE);
}

static e_types	determineType(std::string const& toDet)
{
	size_t			toDetSize = toDet.size();

	switch (toDetSize)
	{
		case 0:
			return (NO_TYPE);
		case 1:
			return (determineOneCharType(toDet));
		default:
			return (determineMultiCharType(toDet, toDetSize));
	}
}

void	ScalarConverter::convert(std::string const& toConvert)
{
	e_types				type;
	std::stringstream	ss(toConvert);

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
