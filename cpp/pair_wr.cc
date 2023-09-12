#include <iostream>

template <typename T1, typename T2>
struct pair {
	T1 first;
	T2 second;

	explicit pair(const T1 &t1, const T2 &t2) : first(t1), second(t2) { }
	~pair() { }

	bool operator==(const pair &r)
	{
		return (this->first == r.first) && (this->second == r.second);
	}
	bool operator!=(const pair &r)
	{
		return !operator==(r);
	}
	bool operator>(const pair &r)
	{
		return (this->first > r.first) && (this->second > r.second);
	}
	bool operator<(const pair &r)
	{
		return !operator>(r);
	}
};

template <typename T1, typename T2>
pair<T1, T2> make_pair(const T1 t1, const T2 t2)
{
	pair<T1, T2> p(t1, t2);

	return p;
}

int main()
{
	pair<std::string, int> p = make_pair<std::string, int>("test", 1);
	pair<std::string, int> p1 = make_pair<std::string, int>("test", 1);

	std::cout << "first: " << p.first << " second: " << p.second << std::endl;
	std::cout << "p == p1: " << (p == p1) << std::endl;
	std::cout << "p != p1: " << (p != p1) << std::endl;

	return 0;
}

