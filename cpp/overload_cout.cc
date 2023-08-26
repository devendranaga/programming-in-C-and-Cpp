#include <iostream>

struct S {
	int a;
	double d;
};

std::ostream &operator<<(std::ostream &os, const S &s)
{
	os << "s.a: " << s.a << " " << "s.d: " << s.d;

	return os;
}

int main()
{
	S s { .a = 3, .d = 3.1 };

	std::cout << s << std::endl;

	return 0;
}

