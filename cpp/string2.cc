#include <iostream>
#include <string>

int main()
{
	std::string r = "hello world";

	for (uint32_t i = 0; i < r.size(); i ++) {
		printf("'%c'", r[i]);
	}
	printf("\n");

	for (uint32_t i = 0; r[i] != '\0'; i ++) {
		printf("'%c'", r[i]);
	}
	printf("\n");

	return 0;
}

