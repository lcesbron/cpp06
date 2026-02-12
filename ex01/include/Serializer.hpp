#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer(void);
		Serializer(Serializer const& toCopy);
		~Serializer(void);
		Serializer&	operator=(Serializer const& toCopy);
	public:
		static uintptr_t	serialize(t_data* ptr);
		static t_data* 		deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
