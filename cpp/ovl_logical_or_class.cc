#include <iostream>

struct S {
	int a;

	uint32_t operator|(const S &r)
	{
		return this->a | r.a;
	}
};

int main()
{
	S r1, r2;

	r1.a = 0x80;
	r2.a = 0x40;

	printf("r1 | r2: 0x%02x\n", r1 | r2);

	return 0;
}

