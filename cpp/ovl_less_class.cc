#include <iostream>

struct S {
	int a;

	bool operator<(const S &r)
	{
		return this->a < r.a;
	}
};

int main()
{
	S s1, s2;

	s1.a = 3;
	s2.a = 6;

	std::cout << "s1 < s2: " << (s1 < s2) << std::endl;
	std::cout << "s2 < s1: " << (s2 < s1) << std::endl;

	return 0;
}

