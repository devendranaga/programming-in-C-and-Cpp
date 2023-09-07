#include <iostream>

enum Languages {
	Telugu		= 0x0001,
	Tamil		= 0x0002,
	English		= 0x0004,
	Hindi		= 0x0008,
};

bool operator<(const Languages &a, int l)
{
	return static_cast<int>(a) < l;
}

std::ostream &operator<<(std::ostream &os, const Languages &l)
{
	std::string r;

	switch (l) {
		case Languages::Telugu:
			r = "Telugu";
		break;
		case Languages::Tamil:
			r = "Tamil";
		break;
		case Languages::English:
			r = "English";
		break;
		case Languages::Hindi:
			r = "Hindi";
		break;
		default:
			r = "Unknown";
		break;
	}

	os << r;

	return os;
}

Languages &operator++(Languages &l)
{
	switch (l) {
		case Languages::Telugu:
			return l = Languages::Tamil;
		break;
		case Languages::Tamil:
			return l = Languages::English;
		break;
		case Languages::Hindi:
			return l = Languages::Telugu;
		break;
		default:
			return l = Languages::Telugu;
		break;
	}
}

int main()
{
	Languages l1 = Languages::Telugu;
	Languages l2 = Languages::Tamil;

	if (l1 == l2) {
		std::cout << "Languages are same" << std::endl;
	} else {
		std::cout << "Languages aren't same" << std::endl;
	}

	if (l1 < l2) {
		std::cout << "l1 is less than l2" << std::endl;
	}

	if (Languages::Hindi < 100) {
		std::cout << "hindi less than 100" << std::endl;
	}

	std::cout << l1 << std::endl;

	++l1;

	std::cout << l1 << std::endl;

	std::cout << std::is_enum_v<Languages> << std::endl;

	return 0;
}


