#include <iostream>

template <typename T>
void print(T val)
{
	std::cout << "template: val: " << val << std::endl;
}

void print(int v)
{
	std::cout << "int: val: " << v << std::endl;
}

int main()
{
	print(3);
	print<std::string>("hello");
	print<int>(3);

	return 0;
}


