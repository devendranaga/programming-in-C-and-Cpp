#include <iostream>

int main()
{
	int *a = new int;

	*a = 3;

	printf("a %d\n", *a);

	delete a;

	return 0;
}

