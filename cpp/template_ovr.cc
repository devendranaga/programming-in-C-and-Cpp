#include <iostream>

template <typename T>
int print(T val)
{
	std::cout << "val: " << val << std::endl;

	return 0;
}

template <typename T, typename R>
int print(T val1, R val2)
{
	std::cout << "val1: " << val1 << " " << "val2: " << val2 << std::endl;

	return 0;
}

int print(int val)
{
	std::cout << "normal val: " << val << std::endl;

	return 0;
}

int main()
{
	print(3);
	print(3, 6);
	print(3u);
	print<int>(3);
}


