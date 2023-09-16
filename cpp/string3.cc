#include <iostream>
#include <string>

int main()
{
	std::string r = "hello world";

	printf("%s\n", r.c_str());

	r.clear();

	printf("%s\n", r.c_str());

	return 0;
}

