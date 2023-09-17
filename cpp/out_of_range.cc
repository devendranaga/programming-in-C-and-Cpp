#include <iostream>
#include <exception>

class S : public std::out_of_range {
	public:
		S(const char *err) : std::out_of_range(err) { }
		~S() { }

		int a;

		void set(int v) {
			if (v > 10) {
				throw *this;
			}
			a = v;
		}

		virtual const char *what() const noexcept {
			return "a value out of range";
		}
};

int main()
{
	S r1("");

	try {
		r1.set(11);
	} catch (S &r) {
		std::cout << r.what() << std::endl;
	}

	return 0;
}

