#include "ScalarConverter.hpp"
#include <cctype>
#include <cfloat>
#include <climits>

void	convertIntToChar(int val, s_value& c)
{
	if (val > CHAR_MAX || val < CHAR_MIN)
	{
		c.overflow = true;
	}
	else
	{
		c.val.c = static_cast<char>(val);
		if (!std::isprint(c.val.c))
		{
			c.non_displyable = true;
		}
	}
}

void	convertFloatToChar(float val, s_value& c)
{
	if (val > CHAR_MAX || val < CHAR_MIN)
	{
		c.overflow = true;
	}
	else
	{
		c.val.c = static_cast<char>(val);
		if (!std::isprint(c.val.c))
		{
			c.non_displyable = true;
		}
	}
}

void	convertFloatToInt(float val, s_value& i)
{
	if (val > static_cast<float>(INT_MAX) || val < INT_MIN)
	{
		i.overflow = true;
	}
	else
	{
		i.val.i = static_cast<int>(val);
	}
}

void	convertDoubleToChar(double val, s_value& c)
{
	if (val > CHAR_MAX || val < CHAR_MIN)
	{
		c.overflow = true;
	}
	else
	{
		c.val.c = static_cast<char>(val);
		if (!std::isprint(c.val.c))
		{
			c.non_displyable = true;
		}
	}
}

void	convertDoubleToInt(double val, s_value& i)
{
	if (val > INT_MAX || val < INT_MIN)
	{
		i.overflow = true;
	}
	else
	{
		i.val.i = static_cast<int>(val);
	}
}

void	convertDoubleToFloat(double val, s_value& f)
{
	if (val > FLT_MAX || val < -FLT_MAX)
	{
		f.overflow = true;
	}
	else
	{
		f.val.f = static_cast<float>(val);
	}
}
