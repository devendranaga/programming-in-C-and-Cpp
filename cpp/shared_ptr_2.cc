#include <iostream>
#include <memory>

struct S {
	int s;
};

int main()
{
	std::shared_ptr<S> s;

	s = std::shared_ptr<S>(new S);

	s->s = 1;

	std::cout << "s->s: " << s->s << std::endl;

	return 0;
}

