#include "ScalarConverter.hpp"
#include <errno.h>
#include <cfloat>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <sstream>
#include <string>

static s_value	computeInt(std::string const& str)
{
	std::stringstream	ss(str);
	s_value	ret;

	ret.overflow = false;
	ss >> ret.val.i;
	if (ss.fail())
	{
		ret.overflow = true;
	}
	return (ret);
}

static s_value	computeFloat(std::string const& str)
{
	s_value	ret ;

	ret.overflow = false;
	ret.val.f = std::strtof(str.c_str(), NULL);
	if (errno)
		ret.overflow = true;
	return (ret);
}

static s_value	computeDouble(std::string const& str)
{
	s_value	ret ;

	ret.overflow = false;
	ret.val.d = std::strtod(str.c_str(), NULL);
	if (errno)
		ret.overflow = true;
	return (ret);
}

s_value	computeValue(std::string const& str, e_types type)
{
	s_value	ret;

	ret.overflow = false;
	switch (type)
	{
		case CHAR:
			ret.val.c = str[0];
			break ;
		case INT:
			ret = computeInt(str);
			break;
		case FLOAT:
			ret = computeFloat(str);
			break;
		case FLOAT_MINF:
			ret.val.f = -std::numeric_limits<float>::infinity();
			break;
		case FLOAT_PINF:
			ret.val.f = std::numeric_limits<float>::infinity();
			break;
		case FLOAT_NAN:
			ret.val.f = NAN;
			break;
		case DOUBLE:
			ret = computeDouble(str);
			break;
		case DOUBLE_MINF:
			ret.val.d = -std::numeric_limits<double>::infinity();
			break;
		case DOUBLE_PINF:
			ret.val.d = std::numeric_limits<double>::infinity();
			break;
		case DOUBLE_NAN:
			ret.val.d = NAN;
			break;
		default:
			break ;
	};
	return (ret);
};
