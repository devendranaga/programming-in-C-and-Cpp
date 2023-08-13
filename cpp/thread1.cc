#include <iostream>
#include <thread>

void thread_1()
{
	std::cout << "in thread_1" << std::endl;
}

void thread_2()
{
	std::cout << "in thread_2" << std::endl;
}

int main()
{
	std::thread t1(thread_1);
	std::thread t2(thread_2);

	std::cout << "waiting for threads" << std::endl;

	t1.join();
	t2.join();

	std::cout << "stop" << std::endl;
}

