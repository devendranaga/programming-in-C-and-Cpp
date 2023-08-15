#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <queue>

template <typename T>
class safe_que {
	public:
		safe_que(const safe_que &) = delete;
		const safe_que &operator=(const safe_que &) = delete;
		safe_que(const safe_que &&) = delete;
		const safe_que &&operator=(const safe_que &&) = delete;

		/**
		 * @brief - get an instance.
		 */
		static safe_que *instance() {
			static safe_que q;
			return &q;
		}
		~safe_que() { }

		/**
		 * @brief - add an element to the safe queue.
		 */
		void add(T &elem) {
			std::unique_lock<std::mutex> lock(lock_);
			items_.push(elem);
			cond_.notify_all();
		}

		/**
		 * @brief - get the element from the queue.
		 */
		void get(T &val) {
			std::unique_lock<std::mutex> lock(lock_);
			cond_.wait(lock);
			val = items_.front();
			items_.pop();
		}

	private:
		explicit safe_que () { }
		std::queue<T> items_;
		std::mutex lock_;
		std::condition_variable cond_;
};

void thread_f()
{
	safe_que<int> *q = safe_que<int>::instance();

	while (1) {
		int data;

		/* Get the element from the queue. */
		q->get(data);
		printf("data %d\n", data);
	}
}

int main()
{
	safe_que<int> *q = safe_que<int>::instance();
	std::thread t(thread_f);
	int count = 0;

	/* Produce data every 100 msec. */
	while (1) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		count ++;

		q->add(count);
	}
}

