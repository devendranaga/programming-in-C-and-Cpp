#include <iostream>

template <typename T>
int binary_search(const T *items, int n, const T item)
{
	int low = 0;
	int high = n - 1;
	int mid = (low + high) / 2;

	while (low <= high) {
		if (items[mid] == item) {
			return mid;
		}

		if (items[mid] < item) {
			low = mid + 1;
		}
		if (items[mid] > item) {
			high = mid - 1;
		}
		mid = (low + high) / 2;
	}

	return -1;
}

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int i;

	i = binary_search(a, 10, 3);

	if (i != -1) {
		printf("a[%d] = %d\n", i, a[i]);
	} else {
		printf("search not found\n");
	}

	return 0;
}


