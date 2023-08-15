#include <iostream>

class F {
	public:
		virtual void f() noexcept = 0;
};

class G : public F {
	public:
		void f() { std::cout << "in f()" << std::endl; }
};

int main()
{
	class G g;

	g.f();
}

