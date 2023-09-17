#include <iostream>

int main()
{
	int *a;
	int i;

	a = new int[10];

	for (i = 0; i < 10; i ++) {
		a[i] = i;
	}

	for (i = 0; i < 10; i ++) {
		std::cout << "a[" << i << "]= " << a[i] << std::endl;
	}

	delete []a;

	return 0;
}

