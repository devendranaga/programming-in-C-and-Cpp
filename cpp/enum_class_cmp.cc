#include <iostream>

enum Languages {
	Telugu,
	Tamil,
	English,
	Hindi,
};

int main()
{
	Languages l1 = Languages::Telugu;
	Languages l2 = Languages::Tamil;

	if (l1 != l2) {
		std::cout << "Languages aren't same" << std::endl;
	}

	return 0;
}


