#include <iostream>

struct S {
	int a;
};

bool operator>(const S &a, const S &l)
{
	return a.a > l.a;
}

int main()
{
	struct S a = { .a = 3 };
	struct S b = { .a = 6 };

	std::cout << "a is greater than b? " << (a > b) << std::endl;

	return 0;
}


