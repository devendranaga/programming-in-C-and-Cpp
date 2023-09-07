#include <iostream>

struct S {
	int a;
	int f;

	bool operator==(const S &other)
	{
		return (this->a == other.a) &&
			   (this->f == other.f);
	}
};

S s1 = { .a = 3, .f = 4 };
S s2 = { .a = 3, .f = 4 };

int main()
{
	if (s1 == s2) {
		std::cout << "s1 and s2 are same" << std::endl;
	} else {
		std::cout << "s1 and s2 are not same" << std::endl;
	}

	return 0;
}

