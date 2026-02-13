#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int	main(void)
{
	Data		a;
	uintptr_t	ptr;

	std::cout << "origigal pointer : " << &a << std::endl;
	ptr = Serializer::serialize(&a);
	std::cout << "serialized pointer : " << ptr << std::endl;
	std::cout << "deserialized pointer : " << Serializer::deserialize(ptr) << std::endl;
}
