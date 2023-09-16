#include <iostream>
#include <vector>

int main()
{
	std::vector<std::vector<int>> r;
	int i;
	int j;

	for (i = 0; i < 3; i ++) {
		std::vector<int> r1;

		for (j = 0; j < 3; j ++) {
			r1.push_back(j + 1 + i);
		}

		r.push_back(r1);
	}

	for (auto it1 : r) {
		for (auto it2 : it1) {
			printf("%d ", it2);
		}
		printf("\n");
	}

	return 0;
}

