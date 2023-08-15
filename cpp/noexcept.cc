#include <iostream>

void f() noexcept { std::cout << "f called" << std::endl; }
void f(std::string arg) { std::cout << "f called with arg: " << arg << std::endl; }

void g() noexcept { throw std::runtime_error("an exception g()"); }

void p() { throw std::runtime_error("an exception p()"); }

int main()
{
	f();
	f("test");

	try {
		p();
	} catch (std::exception &e) {
		std::cout << "caught the exception from function p(): " << e.what() << std::endl;
	}

	try {
		g();
	} catch (...) {
		std::cout << "caught the exception from function g()\n";
	}
}

