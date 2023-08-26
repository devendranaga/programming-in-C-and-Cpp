#include <iostream>

struct S {
	int a;

	S() { a = 0; }
	S(int a) { this->a = a; }

	void operator ++() { a ++; }
};

int main()
{
	S s(3);

	++s;

	std::cout << s.a << std::endl;
}

