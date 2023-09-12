#include <iostream>

int F(int a)
{
	printf("in F %d\n", a);

	return 0;
}

int F(int n, ...)
{
	printf("in V_F %d\n", n);

	return 0;
}

int main()
{
	F(1);
	F(3, 1, 2, 3);

	return 0;
}



