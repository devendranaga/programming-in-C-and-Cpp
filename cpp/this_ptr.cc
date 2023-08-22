#include <iostream>

class S {
	public:
		S() { a_ = 0; }
		~S() { }

		int get() { return this->a_; }
		void set(int a) { this->a_ = a; }

	private:
		int a_;
};

int main()
{
	S s;

	s.set(3);
	std::cout << "val " << s.get() << std::endl;

	return 0;
}

