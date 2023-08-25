#include <iostream>

struct A {
	int val;
};

A operator+(A a, A b)
{
	A r;

	r.val = a.val + b.val;

	return r;
}

int main()
{
	A a { .val = 3 };
	A b { .val = 3 };

	A r = a + b;

	std::cout << "r val " << r.val << std::endl;

	return 0;
}


