#include <iostream>
#include <array>

int main()
{
	std::array<int, 10> a;
	int i;

	for (i = 0; i < a.size(); i ++) {
		a[i] = i + i;
	}

	for (i = 0; i < a.size(); i ++) {
		std::cout << "i : " << i << " "  << "a[i] : " << a.at(i) << std::endl;
	}

	return 0;
}

