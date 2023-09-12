#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T t;

	t = a;
	a = b;
	b = t;
}

template <typename T>
void insert_sort(T *items, size_t len)
{
	int j;
	int i;
	int iterations = 0;

	for (j = 1; j < len; j ++) {
		T key = items[j];
		i = j - 1;
		while (i >= 0) {
			if (items[i] > key) {
				swap(items[i + 1], items[i]);
			}
			i --;
			iterations ++;
		}
	}
}

int main()
{
	int a[6] = {5,2,4,6,1,3};
	int i;

	insert_sort(a, 6);

	for (i = 0; i < sizeof(a)/ sizeof(a[0]); i ++) {
		printf("a[%d] = %d\n", i, a[i]);
	}

	return 0;
}



