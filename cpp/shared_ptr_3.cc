#include <iostream>

template <typename T>
class shared_ptr {
	public:
		explicit shared_ptr() : count_(0), memory_(nullptr) {
		}
		explicit shared_ptr(T *t) : count_(0) {
			memory_ = t;
			count_ ++;
		}

		shared_ptr(const shared_ptr &t) {
			count_ = 0;
			memory_ = nullptr;
			memory_ = t.memory_;
			count_ = t.count_ + 1;
		}

		~shared_ptr() {
			count_ --;
			if (memory_ && (count_ == 0)) {
				delete memory_;
			}
		}
		void set(T *memory) {
			memory_ = memory;
			count_ ++;
		}

		T *get() const noexcept { return memory_; }

		bool unique() const { return count_ == 1; }

		T *operator->() const { return memory_; }
		T &operator*() const { return *memory_; }

		int get_ref_count() { return count_; }

	private:
		int count_;
		T *memory_;
};

struct S {
	int s;
};

void K(shared_ptr<S> s)
{
	std::cout << "ref_counter for s: " << s.get_ref_count() << std::endl;
	std::cout << "unique s: " << s.unique() << std::endl;
	s->s = 6;
}

int main()
{
	shared_ptr<S> s = shared_ptr<S>(new S);
	shared_ptr<int> s1 = shared_ptr<int>(new int);

	s->s = 3;
	*s1 = 3;

	std::cout << "ref_counter for s: " << s.get_ref_count() << std::endl;
	std::cout << "ref_counter for s1: " << s1.get_ref_count() << std::endl;

	std::cout << "unique s: " << s.unique() << " unique s1: " << s1.unique() << std::endl;

	K(s);

	std::cout << "ref_counter for s: " << s.get_ref_count() << std::endl;
	std::cout << "ref_counter for s1: " << s1.get_ref_count() << std::endl;

	std::cout  << "s: " << s->s << " " << "s1: " << *s1 << std::endl;

	std::cout << "s1: " << s1.get() << std::endl;

	return 0;
}



