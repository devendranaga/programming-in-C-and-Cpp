#include <iostream>
#include <typeinfo>

int main()
{
	auto i = 4;
	auto p = "test";

	std::cout << typeid(i).name() << std::endl;
	std::cout << typeid(p).name() << std::endl;
}

