#include <iostream>

struct S {
	public:
		S() { a = 0; }
		~S() { }

		int get() { return a; }
		void set(int a) { this->a = a; }

	private:
		int a;
};

int main()
{
	S s;

	s.set(3);
	std::cout << "val " << s.get() << std::endl;

	return 0;
}

