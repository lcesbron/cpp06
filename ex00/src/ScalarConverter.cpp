#include "ScalarConverter.hpp"
#include <cctype>
#include <cstddef>
#include <sstream>
#include <ctype.h>
#include <string>

#define NUM 1
#define FLT 1 << 1

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
	if (isdigit(toDet[0]))
		return (INT);
	if (isprint(toDet[0]))
		return (CHAR);
	return (NO_TYPE);
}

static e_types	determineMultiCharType(std::string const& toDet, size_t toDetSize)
{
	unsigned int	toDetFlags = 0;
	size_t			i;

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

	i = (toDet[0] == '+' || toDet[0] == '-') ? 1 : 0;
	while (i++ < toDetSize && isdigit(toDet[i]));
	if (toDet[i] != '.')
	{
		toDetFlags += FLT;
		while (i++ < toDetSize && isdigit(toDet[i]));
		if (i == toDetSize)
			return (DOUBLE);
	}
	if (toDet[i] == 'f')
		return (FLOAT);
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
}
