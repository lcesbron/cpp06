#include "ScalarConverter.hpp"
#include <cctype>
#include <ctype.h>

static e_types	determineChar(std::string const& toDet)
{
	if (std::isprint(toDet[1]) && toDet[2] == '\'')
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
		if (i == toDetSize)
			return (DOUBLE);
	}
	else if (sign && i == 1)
	{
		return (NO_TYPE);
	}
	else if (i == toDetSize)
		return (INT);
	if (toDet[i] == 'f' && i == toDetSize - 1)
		return (FLOAT);
	return (NO_TYPE);
}

e_types	determineType(std::string const& toDet)
{
	size_t			toDetSize = toDet.size();

	if (!toDetSize)
		return (NO_TYPE);
	if (toDet[0] == '\'' && toDetSize == 3)
		return (determineChar(toDet));
	else
		return (determineMultiCharType(toDet, toDetSize));
}
