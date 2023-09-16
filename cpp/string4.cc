#include <iostream>
#include <string>

int main()
{
	std::string r1 = "r1";
	std::string r2 = "r2";
	std::string r3 = r1 + r2;

	printf("r1: %s r2: %s r3: %s\n", r1.c_str(), r2.c_str(), r3.c_str());

	return 0;
}

