#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>

Base * generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated B" << std::endl;
			return (new B());
		default:
			std::cout << "Generated C" << std::endl;
			return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "type is A" << std::endl;
	}
	if (dynamic_cast<B*>(p))
	{
		std::cout << "type is B" << std::endl;
	}
	if (dynamic_cast<C*>(p))
	{
		std::cout << "type is C" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
	}
	catch (std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
		}
		catch (std::exception& r)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
			}
			catch (std::exception& t) {}
			std::cout << "type is C" << std::endl;
			return ;
		}
		std::cout << "type is B" << std::endl;
		return ;
	}
	std::cout << "type is A" << std::endl;
}

int	main(void)
{
	std::srand(std::time(NULL));
	std::cout << "================== PTR ==================" << std::endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		Base*	ptr = generate();
		identify(ptr);
		delete (ptr);
	}
	std::cout << "================== REF ==================" << std::endl;
	for (unsigned int i = 0; i < 5; i++)
	{
		Base*	ptr = generate();
		identify(*ptr);
		delete (ptr);
	}
}
