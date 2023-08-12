#include <iostream>
#include <thread>

void thread_f()
{
	std::cout << "in thread" << std::endl;
}

int main()
{
	std::thread t(thread_f);

	std::cout << "starting thread" << std::endl;
	t.join();
	std::cout << "joined thread" << std::endl;
}

