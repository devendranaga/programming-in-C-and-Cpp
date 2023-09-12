#include <iostream>

int main()
{
	auto r = std::pair<std::string, int>("test", 1);
	auto r1 = std::pair<std::string, int>("test", 1);

	std::cout << "r == r1: " << (r == r1) << std::endl;

	return 0;
}

