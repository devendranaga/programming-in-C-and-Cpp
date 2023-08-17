#include <iostream>
#include <memory>

struct P {
	int val;
};

void print(std::shared_ptr<P> p)
{
	struct P *p1;

	p1 = p.get();
	printf("p->val %d deref->val %d\n", p->val, p1->val);
	printf("p.val %d\n", (*p).val);
	printf("use_count %ld\n", p.use_count());
}

int main()
{
	std::shared_ptr<P> ptr;

	ptr = std::make_shared<P>();
	ptr->val = 4;

	print(ptr);

	return 0;
}

