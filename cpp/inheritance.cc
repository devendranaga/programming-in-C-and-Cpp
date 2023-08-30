#include <iostream>

struct B {
	public:
		B() { a_ = 3; }
		~B() { };
		int get() { return a_; }

	private:
		int a_;
};

struct D : public B {
	public:
		D() { a_ = 6; };
		~D() { };
		int get() { return a_; }
		int get_b() { return B::get(); }

	private:
		int a_;
};

int main()
{
	D d;

	std::cout << "d.a: " << d.get()
			  << " d.B::a: " << d.B::get()
			  << " b.a: " << d.get_b() << std::endl;

	return 0;
}

