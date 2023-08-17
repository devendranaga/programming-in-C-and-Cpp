#include <iostream>
#include <thread>
#include <mutex>

std::mutex lock;
static int count;

void thread_1()
{
	while (1) {
		std::cout << "in thread_1: waiting for lock" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		lock.lock();
		std::cout << "in thread_1: acquired" << std::endl;
		count ++;
		std::cout << "in thread_1: val " << count << std::endl;
		std::cout << "in thread_1: released" << std::endl;
		lock.unlock();
	}
}

void thread_2()
{
	while (1) {
		std::cout << "in thread_2: waiting for lock" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		lock.lock();
		std::cout << "in thread_2: acquired" << std::endl;
		count ++;
		std::cout << "in thread_2: val " << count << std::endl;
		std::cout << "in thread_2: released" << std::endl;
		lock.unlock();
	}
}

int main()
{
	std::thread t1(thread_1);
	std::thread t2(thread_2);

	t1.join();
	t2.join();
}


