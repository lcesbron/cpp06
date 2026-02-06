#include "ScalarConverter.hpp"
#include

u_value	computeValue(std::string const& str, e_types type)
{
	u_value	ret;
	switch (type)
	{
		case CHAR:
			ret.c = str[0];
			break ;
		case INT: // detect Overflow
			ret.i = std::atoi(str.c_str());
	}
	return (ret)
};
