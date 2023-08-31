#include <iostream>

int main()
{
	std::string str = "tests";

	std::cout << "str: " << str
			  << " c_str(): " << str.c_str()
			  << " front(): " << str.front()
			  << " back(): " << str.back() << std::endl;

	return 0;
}

