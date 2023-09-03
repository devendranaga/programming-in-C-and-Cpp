#include <iostream>
#include <vector>

struct S {
	int age;
	std::string name;
};

static void it_const_print(const std::vector<S> &group)
{
	std::vector<S>::const_iterator it_c;

	std::cout << "normal iterator: [" << group.size() << "] " << std::endl;

	for (it_c = group.begin(); it_c != group.end(); it_c ++) {
		std::cout << "\t name: " << it_c->name << " "
				  << "age: " << it_c->age << std::endl;
	}
}

static void range_for_print(const std::vector<S> &group)
{
	std::cout << "auto iteration: [" << group.size() << "] " << std::endl;

	for (auto it : group) {
		std::cout << "\t name: " << it.name << " "
				  << "age: " << it.age << std::endl;
	}
}

static void reverse_for_print(std::vector<S> &group)
{
	std::vector<S>::reverse_iterator it_r;

	std::cout << "reverse iterator: [" << group.size() << "] " << std::endl;

	for (it_r = group.rbegin(); it_r != group.rend(); it_r ++) {
		std::cout << "\t name: " << it_r->name << " "
				  << "age: " << it_r->age << std::endl;
	}
}

static void at_print(std::vector<S> &group)
{
	int i;

	std::cout << "at: [" << group.size() << "] " << std::endl;

	for (i = 0; i < group.size(); i ++) {
		std::cout << "\t name: " << group[i].name << " "
				  << "age: " << group[i].age << std::endl;
	}
}

int main()
{
	std::vector<S> group;
	std::vector<S> group2;

	group.push_back({32, "Dev"});
	group.push_back({33, "Seema"});
	group.push_back({34, "Cap"});

	group2.push_back({50, "Hannibal"});
	group2.push_back({30, "BA"});
	group2.push_back({30, "Peck"});
	group2.push_back({30, "Murdoch"});

	it_const_print(group);
	range_for_print(group);
	reverse_for_print(group);
	at_print(group);

	std::vector<S>::iterator it;

	for (it = group.begin(); it != group.end(); it ++) {
		if (it->age == 34) {
			break;
		}
	}

	// Erasing
	if (it != group.end()) {
		group.erase(it);
	}

	std::cout << "merging with another vector: " << std::endl;
	group.insert(group.end(),
				 group2.begin(), group2.end());

	group.resize(7);
	group.at(6).age = 30;
	group.at(6).name = "test";

	std::cout << "first " << group.begin()->age << std::endl;
	std::cout << "last " << (group.end() - 1)->age << std::endl;

	range_for_print(group);

	group.clear();
	range_for_print(group);

	return 0;
}

