#include <iostream>

enum class fruits {
	Apple,
	Oranges,
	Banana,
};

int main()
{
	fruits f = fruits::Apple;

	std::cout << (int)f << std::endl;

	return 0;
}

