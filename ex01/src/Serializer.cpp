#include "Serializer.hpp"
#include <stdint.h>

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const& toCopy) {(void)toCopy;}

Serializer::~Serializer(void) {}

Serializer&	Serializer::operator=(Serializer const& toCopy) {(void)toCopy; return (*this);}

uintptr_t	Serializer::serialize(t_data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

t_data* 		Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<t_data*>(raw));
}
