#include <iostream>

template <typename T>
void bubble_sort(T *a, int n)
{
	int i;
	int j;
	int iters = 0;
	bool sorted = false;

	for (i = 0; i < n - 1; i ++) {
		for (j = 0; j < n - i - 1; j ++) {
			if (a[j] > a[j + 1]) {
				T t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				sorted = true;
			}
			iters ++;
		}
	}

	std::cout << "iters: " << iters << std::endl;
}

int main()
{
	int a[10] = {91, 19, 1, -1, 11, -18, 29, 7, 9, 10};

	bubble_sort<int>(a, sizeof(a) / sizeof(a[0]));

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i ++) {
		std::cout << a[i] << std::endl;
	}

	return 0;
}


