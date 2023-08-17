#include <iostream>
#include <memory>

struct P {
	int val;
};

void print(std::unique_ptr<P> &p)
{
	printf("val %d\n", p->val);
}

int main()
{
	std::unique_ptr<P> ptr;

	ptr = std::make_unique<P>();
	ptr->val = 4;

	print(ptr);
	return 0;
}

