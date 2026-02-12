#include "ScalarConverter.hpp"
#include "convert.h"
#include <cctype>
#include <climits>
#include <cmath>
#include <csignal>
#include <iomanip>
#include <iostream>
#include <limits>
#include <linux/limits.h>
#include <ostream>

static void	convertFromChar(char val, char& c, int& i, float& f, double& d)
{
	c = val;
	i = static_cast<int>(val);
	f = static_cast<float>(val);
	d = static_cast<double>(val);
}

static void	convertFromInt(s_value val, s_value& c, s_value& i, s_value& f, s_value& d)
{
	if (val.overflow)
	{
		i.overflow = true;
		c.impossible = true;
		f.impossible = true;
		d.impossible = true;
	}
	else
	{
		convertIntToChar(val.val.i, c);
		i.val.i = val.val.i;
		f.val.f = static_cast<float>(val.val.i);
		d.val.d = static_cast<double>(val.val.i);
	}
}

static void	convertFromFloat(s_value val, s_value& c, s_value& i, s_value& f, s_value& d)
{
	if (val.overflow)
	{
		f.overflow = true;
		c.impossible = true;
		i.impossible = true;
		d.impossible = true;
	}
	else if (val.val.f != val.val.f || val.val.f == std::numeric_limits<float>::infinity() || val.val.f == -std::numeric_limits<float>::infinity())
	{
		f.val.f = val.val.f;
		d.val.d = val.val.f;
		c.impossible = true;
		i.impossible = true;
	}
	else
	{
		f.val.f = val.val.f;
		d.val.d = val.val.f;
		convertFloatToChar(val.val.f, c);
		convertFloatToInt(val.val.f, i);
	}
}

static void	convertFromDouble(s_value val, s_value& c, s_value& i, s_value& f, s_value& d)
{
	if (val.overflow)
	{
		d.overflow = true;
		c.impossible = true;
		i.impossible = true;
		f.impossible = true;
	}
	else if (val.val.d != val.val.d || val.val.d == std::numeric_limits<float>::infinity() || val.val.d == -std::numeric_limits<float>::infinity())
	{
		d.val.d = val.val.d;
		f.val.f = static_cast<float>(val.val.d);
		c.impossible = true;
		i.impossible = true;
	}
	else
	{
		d.val.d = val.val.d;
		convertDoubleToChar(val.val.d, c);
		convertDoubleToInt(val.val.d, i);
		convertDoubleToFloat(val.val.d, f);
	}
}

std::ostream&	operator<<(std::ostream& os, s_value& val)
{
	if (val.overflow)
	{
		os << "overflow";
	}
	else if (val.impossible)
	{
		os << "impossible";
	}
	else if (val.non_displyable)
	{
		os << "non displayable";
	}
	else if (val.type == CHAR)
	{
		os << "'" << val.val.c << "'";
	}
	else if (val.type == INT)
	{
		os << val.val.i;
	}
	else if (val.type >= FLOAT && val.type < DOUBLE)
	{
		os << std::fixed << std::setprecision(10) << val.val.f << 'f';
	}
	else if (val.type >= DOUBLE)
	{
		os << std::fixed << std::setprecision(10) << val.val.d;
	}
	return (os);
}

void	printValues(s_value val)
{
	s_value	c = (s_value){0, 0, 0, CHAR, {0}};
	s_value	i = (s_value){0, 0, 0, INT, {0}};
	s_value	f = (s_value){0, 0, 0, FLOAT, {0}};
	s_value	d = (s_value){0, 0, 0, DOUBLE, {0}};

	if (val.type == CHAR)
	{
		convertFromChar(val.val.c, c.val.c, i.val.i, f.val.f, d.val.d);
	}
	else if (val.type == INT)
	{
		convertFromInt(val, c, i, f, d);
	}
	else if (val.type >= FLOAT && val.type < DOUBLE)
	{
		convertFromFloat(val, c, i, f, d);
	}
	else if (val.type >= DOUBLE)
	{
		convertFromDouble(val, c, i, f, d);
	}
	else if (val.type == NO_TYPE)
	{
		c.impossible = true;
		i.impossible = true;
		f.impossible = true;
		d.impossible = true;
	}
	std::cout << "char : " << c << std::endl;
	std::cout << "int : " << i << std::endl;
	std::cout << "float : " << f << std::endl;
	std::cout << "double : " << d << std::endl;
}
