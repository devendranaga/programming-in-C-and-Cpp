#include <iostream>

template <typename T, typename R = int>
void f(T a, R b)
{
	std::cout << "a: " << a << " "
			  << "b: " << b << std::endl;
}

int main()
{
	f<double>(1.1, 1);
	f<double, double>(1.1, 2.2);

	return 0;
}

