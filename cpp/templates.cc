#include <iostream>

template <typename T>
class calculator {
	public:
		T add(T a, T b) { return a + b; }
		T sub(T a, T b) { return a - b; }
		T mul(T a, T b) { return a * b; }
		T div(T a, T b) { return a / b; }
		T mod(T a, T b) { return a % b; }
};

int main()
{
	calculator<int> cal;

	std::cout << "Add: " << cal.add(3, 3) << std::endl;
	std::cout << "Sub: " << cal.sub(3, 3) << std::endl;
	std::cout << "Mul: " << cal.mul(3, 3) << std::endl;
	std::cout << "Div: " << cal.div(3, 3) << std::endl;
	std::cout << "Mod: " << cal.mod(3, 3) << std::endl;

	return 0;
}

