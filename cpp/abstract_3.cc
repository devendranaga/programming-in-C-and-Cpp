#include <iostream>
#include <memory>

class polygon {
	public:
		virtual int area(int a, int b) { return a * b; }
};

class rectangle : public polygon {
};

class square : public polygon {
	public:
		int area(int a) { return a * a; }
};

int main()
{
	polygon *r;

	r = new rectangle;

	std::cout << "rectangle: area: " << r->area(3, 6) << std::endl;

	r = new square;

	std::cout << "square: area: " << r->area(3) << std::endl;

	return 0;
}


