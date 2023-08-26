#include <iostream>

class S {
	public:
		virtual int get() = 0;
};

class R: public S {
	public:
		R() { a_ = 3; }
		~R() { }

		int get() { return a_; }

	private:
		int a_;
};

int main()
{
	R r;

	std::cout << "R: " << r.get() << std::endl;

	return 0;
}

