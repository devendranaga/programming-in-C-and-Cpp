#include <iostream>

struct S {
	int a;
};

int main()
{
	S *r;

	r = new S;

	r->a = 3;

	std::cout << "r->a: " << r->a << std::endl;

	delete r;

	return 0;
}

