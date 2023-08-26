#include <iostream>

class P {
	public:
		P()
		{
			std::cout << "default constructor" << std::endl;
			a = 3;
		}
		~P()
		{
			std::cout << "destructor called" << std::endl;
		}

		int get() { return a; }

	private:
		int a;
};

int main()
{
	P p;

	std::cout << "p.a: " << p.get() << std::endl;

	return 0;
}

