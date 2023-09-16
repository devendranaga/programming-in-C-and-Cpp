#include <iostream>

class S {
	public:
		S(int r) : a(r) { }
		~S() { }

		friend std::ostream &operator<<(std::ostream &os, const S &r);

	private:
		int a;
};

std::ostream &operator<<(std::ostream &os, const S &r)
{
	os << " r.a: " << r.a;

	return os;
}

int main()
{
	S s1(3), s2(6);

	std::cout << s1 << s2 << std::endl;
}

