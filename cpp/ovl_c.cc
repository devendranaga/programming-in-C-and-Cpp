#include <iostream>

struct S {
	int a;
	int f;
};

bool operator==(const S &l, const S &r)
{
	return (l.a == r.a) && (l.f == r.f);
}

int main()
{
	S s1 = { .a = 3, .f = 1 };
	S s2 = { .a = 6, .f = 1 };

	if (s1 == s2) {
		std::cout << "s1 and s2 are same" << std::endl;
	} else {
		std::cout << "s1 and s2 are not same" << std::endl;
	}

	return 0;
}


