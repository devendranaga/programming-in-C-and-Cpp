#include <iostream>
#include <list>

int main()
{
	std::list<int> l;
	std::list<int> r;
	std::list<int>::iterator it;
	std::list<int>::reverse_iterator rit;

	l.push_front(3);
	l.push_back(1);
	l.push_back(6);
	l.push_back(2);

	/* Normal iterator. */
	std::cout << "normal iterator: " << std::endl;
	for (it = l.begin(); it != l.end(); it ++) {
		std::cout << *it << std::endl;
	}

	/* Reverse iterator. */
	std::cout << "reverse iterator: " << std::endl;
	for (rit = l.rbegin(); rit != l.rend(); rit ++) {
		std::cout << *rit << std::endl;
	}

	std::cout << "auto iteartor: " << std::endl;
	/* Auto iterator. */
	for (auto it : l) {
		std::cout << it << std::endl;
	}

	std::cout << "front: " << l.front() << std::endl;
	std::cout << "back: " << l.back() << std::endl;

	r = l;

	std::cout << "normal iterator: " << std::endl;
	for (it = r.begin(); it != r.end(); it ++) {
		std::cout << *it << std::endl;
	}

	r.insert(r.end(), l.begin(), l.end());

	std::cout << "normal iteration after insert: " << std::endl;
	for (it = r.begin(); it != r.end(); it ++) {
		std::cout << *it << std::endl;
	}

	std::cout << "r empty: " << r.empty() << std::endl;

	r.erase(r.begin(), std::next(r.begin(), 2));
	r.erase(r.begin(), r.end());

	std::cout << "r empty: " << r.empty() << std::endl;
	std::cout << "r size: " << r.size()
			  << " r max size: " << r.max_size() << std::endl;
	std::cout << "l size: " << l.size()
			  << " l max size: " << l.max_size() << std::endl;

	return 0;
}

