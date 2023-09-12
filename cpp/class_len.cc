#include <iostream>

class S {
	public:
		int get() { return a; }

	private:
		int a;
		int p;
		double r;
};

int main()
{
	std::cout << "size: " << sizeof(S) << std::endl;

	return 0;
}

