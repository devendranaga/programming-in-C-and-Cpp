#include <iostream>

void f(std::pair<const std::string, int> p)
{
	std::cout << "first: " << p.first << " second: " << p.second << std::endl;
}

int main()
{
	f(std::make_pair("test", 1));
	f(std::make_pair<std::string, int>("test", 2));
	f(std::pair("test", 1));
}


