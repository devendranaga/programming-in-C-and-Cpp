#include <iostream>
#include <queue>

int main()
{
	std::queue<int> q;
	int size;

	printf("q empty %d\n", q.empty());

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);

	printf("number of elements %lu, queue empty %d\n", q.size(), q.empty());
	printf("front %d back %d\n", q.front(), q.back());

	while (1) {
		size = q.size();
		if (size <= 0) {
			break;
		}

		int val = q.front();
		q.pop();
		printf("val : %d\n", val);
	}
}

