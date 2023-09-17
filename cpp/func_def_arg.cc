#include <iostream>

int f(int a, int b = 10)
{
	return a + b;
}

int main()
{
	int r = f(10);

	std::cout << "r: " << r << std::endl;

	r = f(3, 3);

	std::cout << "r: " << r << std::endl;

	return 0;
}


