/**
 * @brief - Thread pool implementation within 200 lines.
 *
 * @author - Devendra Naga (github.com/devendranaga/)
 *
 * @copyright - 2023-present.
 * @license - GPLv2
 */
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

typedef std::function<void(void)> work_fn;

class TD {
	public:
		explicit TD(uint32_t id) : id_(id), queue_size_(0), queued_(false), signalled_(false)
		{
			t_ = std::make_shared<std::thread>(&TD::thread_fn, this);
		}
		~TD () { }

		void queue(work_fn fn)
		{
			{
				std::unique_lock<std::mutex> l(lock_);
				queued_ = true;
				queue_size_ ++;
				work_list_.push(fn);
				cond_.notify_one();
			}
		}

		uint32_t get_id() { return id_; }

		void join() { t_->join(); }

		int get_queue_size() { return queue_size_; }

		void signal()
		{
			std::unique_lock<std::mutex> l(lock_);
			signalled_ = true;
			cond_.notify_one();
		}

	private:
		uint32_t id_;
		int queue_size_;
		bool queued_;
		bool signalled_;
		std::queue<work_fn> work_list_;
		std::shared_ptr<std::thread> t_;
		std::mutex lock_;
		std::condition_variable cond_;

		void thread_fn()
		{
			int queue_size = 0;
			work_fn fn = nullptr;

			while (1) {
				{
					fn = nullptr;
					std::unique_lock<std::mutex> l(lock_);
					if (queue_size == 0) {
						cond_.wait(l, [this] { return (queued_ == true) || (signalled_ == true); });
						if (signalled_) {
							break;
						}
						queued_ = false;
					}
					queue_size = work_list_.size();
					if (queue_size > 0) {
						fn = work_list_.front();
						work_list_.pop();

						printf("remaining items in thread %d %d\n", id_, queue_size_);

					}
				}
				if (fn) {
					fn();
					queue_size_ --;
				}
			}
		}
};

class TP {
	public:
		explicit TP(int n_threads) : n_threads_(n_threads)
		{
			int i;

			for (i = 0; i < n_threads; i ++) {
				std::shared_ptr<TD> td;

				td = std::make_shared<TD>(i);
				td_list_.push_back(td);
			}
		}

		void queue(work_fn fn)
		{
			int lowest = td_list_.begin()->get()->get_queue_size();
			std::vector<std::shared_ptr<TD>>::iterator it;
			std::vector<std::shared_ptr<TD>>::iterator lowest_it = td_list_.end();

			for (it = td_list_.begin(); it != td_list_.end(); it ++) {
				int q_size = it->get()->get_queue_size();
				if (q_size <= lowest) {
					lowest = q_size;
					lowest_it = it;
				}
			}

			printf("chose lowest id [%d] queue [%d]\n", lowest_it->get()->get_id(), lowest_it->get()->get_queue_size());
			if (lowest != -1) {
				lowest_it->get()->queue(fn);
			}
		}

		void run()
		{
			for (auto it : td_list_) {
				it.get()->join();
			}
		}

		void signal()
		{
			for (auto it : td_list_) {
				it.get()->signal();
			}
		}

	private:
		int n_threads_;
		std::vector<std::shared_ptr<TD>> td_list_;
};

static int count;
std::mutex lock;

void work_1()
{
	fprintf(stderr, "executing infinite loop\n");
	while (1) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		{
			std::unique_lock<std::mutex> l(lock);
			fprintf(stderr, "work_1: counter: %d\n", count);
			if (count > 1) {
				break;
			}
		}
	}
}

void work_2()
{
	std::unique_lock<std::mutex> l(lock);
	fprintf(stderr, "work_2: counter: %d\n", count);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	count ++;
}

void work_3()
{
	std::unique_lock<std::mutex> l(lock);
	fprintf(stderr, "work_3: counter: %d\n", count);
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	count ++;
}

int main()
{
	TP t(4);
	int i;

	t.queue(&work_1);

	for (i = 0; i < 10; i ++) {
		t.queue(&work_3);
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		t.queue(&work_2);
	}

	t.signal();

	t.run();
}

