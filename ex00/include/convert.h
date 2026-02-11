#ifndef CONVERT_H
# define CONVERT_H

# include "ScalarConverter.hpp"

void	convertIntToChar(int val, s_value& c);
void	convertFloatToChar(float val, s_value& c);
void	convertFloatToInt(float val, s_value& i);
void	convertDoubleToFloat(double val, s_value& f);
void	convertDoubleToInt(double val, s_value& i);
void	convertDoubleToChar(double val, s_value& c);

#endif //CONVERT_H
