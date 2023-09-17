#include <iostream>

struct S {
	int a;
};

int main()
{
	int *r1;
	S *r2;
	int *r3;

	r1 = (int *)malloc(sizeof(int));
	if (!r1) {
		return -1;
	}

	*r1 = 3;

	r2 = (S *)calloc(1, sizeof(S));
	if (!r2) {
		return -1;
	}

	r2->a = 9;

	r3 = NULL;

	r3 = (int *)realloc(r3, sizeof(int));
	if (!r3) {
		return -1;
	}

	*r3 = 6;

	std::cout << "r1: " << *r1 << " r2: " << r2->a << " r3: " << *r3 << std::endl;

	free(r1);
	free(r2);
	free(r3);

	return 0;
}

