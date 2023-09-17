#include <iostream>

struct S {
	S(int r) {
		if (r == 0) {
			throw std::runtime_error("r is 0");
		}
	}

	int a;
};

int main()
{
	try {
		S r1(0);
	} catch (std::runtime_error &r) {
		std::cout << "exception: " << r.what() << std::endl;
	}

	S r2(3);

	return 0;
}

