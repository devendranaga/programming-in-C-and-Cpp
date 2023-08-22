#include <iostream>

int main()
{
	int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (auto i : a) {
		printf("%d\n", i);
	}

	return 0;
}

