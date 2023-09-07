#include <iostream>
#include <memory>

struct S {
	int a;
};

int main()
{
	std::shared_ptr<S> s1 = 0;

	std::cout << "a: " << s1->a << std::endl;

	return 0;
}

