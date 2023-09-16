#include <iostream>

struct S {
	S(int r) {
		a = new int;
		*a = r;
	}
	~S() {
		if (a != nullptr) {
			delete a;
		}
	}

	int *a;

	int operator*() {
		return *a;
	}
};

int main()
{
	S r1(3), r2(6);

	std::cout << "r1: " << *r1 << " " << "r2: " << *r2 << std::endl;

	return 0;
}

