#include <iostream>

struct S {
	int a;

	bool operator>=(const S &r)
	{
		return this->a >= r.a;
	}
};

int main()
{
	S r1, r2, r3;

	r1.a = 3;
	r2.a = 4;
	r3.a = 3;

	std::cout << "r1 > r2: " << (r1 >= r2)
			  << " r2 > r1: " << (r2 >= r1)
			  << " r3 == r1: " << (r3 >= r1) << std::endl;
	return 0;
}



