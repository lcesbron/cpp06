#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

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

union u_value
{
	char	c;
	int		i;
	float	f;
	double	d;
};

class ScalarConverter
{
	public:
		static void	convert(std::string const& toConvert);
};

e_types	determineType(std::string const& toDet);

#endif //SCALARCONVERTER_HPP
