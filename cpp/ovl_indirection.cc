#include <iostream>

struct S {
	int a;
};

S operator*(const S &r1, const S &r2)
{
	S r;

	r.a = r1.a * r2.a;

	return r;
}

int main()
{
	S r1, r2, r;

	r1.a = 3;
	r2.a = 6;

	r = r1 * r2;

	std::cout << "r: " << r.a << std::endl;

	return 0;
}


