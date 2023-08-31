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
	std::cout << "joinable: " << ( t.joinable() ? "yes": "no" ) << std::endl;
	std::cout << "thread_id: " << t.get_id() << std::endl;
	std::cout << "hardware_concurrency: " <<
						t.hardware_concurrency() << std::endl;
	t.join();
	std::cout << "joined thread" << std::endl;
}

