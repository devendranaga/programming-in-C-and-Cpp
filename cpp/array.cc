#include <iostream>

template <typename T, int n>
class array {
	public:
		explicit array() = default;
		~array() = default;

		T &operator[](int index) { return array_[index]; }

		T at(int index) { return array_[index]; }

		int size() { return n; }

		void clear() {
			for (auto i = 0; i < n; i ++) {
				array_[i] = 0;
			}
		}
	private:
		T array_[n];
};

int main()
{
	array<int, 10> a;

	a[1] = 4;

	std::cout << "array " << a[1] << std::endl;
}


