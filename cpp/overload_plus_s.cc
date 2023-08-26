#include <iostream>

struct S {
	int a;

	S() { a = 0; }
	S(int a) { this->a = a; }
	~S() { }

	S operator+(const S &s)
	{
		S r;

		r.a = this->a + s.a;

		return r;
	}
};

int main()
{
	S s(3);
	S r(3);
	S t;

	t = s + r;

	std::cout << "t.a: " << t.a << std::endl;

	return 0;
}

