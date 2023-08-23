#include <iostream>

/**
 * Defines a cache line item
 */
template <typename T>
struct lru_cache_items {
	T val;
	bool is_avail;
	uint32_t seq_no;
};

/**
 * Template of the lru_cache.
 */
template <typename T, int n>
class lru_cache {
	public:
		explicit lru_cache()
		{
			index_ = 0;
			seq_no_ = 0;

			for (auto i = 0; i < n; i ++) {
				items_[i].is_avail = false;
				items_[i].seq_no = 0;
			}
		}
		~lru_cache() { }

		lru_cache &push(T &val)
		{
			/* Add to the cache for the first n items */
			if (index_ < n) {
				seq_no_ ++;

				items_[index_].val = val;
				items_[index_].is_avail = true;
				items_[index_].seq_no = seq_no_;

				index_ ++;
			} else {
				/**
				 * Try evicting an item if the item is old.
				 *
				 * if the particular cache line's sequence number is oldest, evict it and update the item.
				 */

				/* Find least recently used. */
				int i;
				int index = -1;
				uint32_t least_val = seq_no_;

				for (i = 0; i < n; i ++) {
					if (items_[i].seq_no < least_val) {
						least_val = items_[i].seq_no;
						index = i;
					}
				}

				if (index != -1) {
					seq_no_ ++;

					items_[index].val = val;
					items_[index].is_avail = true;
					items_[index].seq_no = seq_no_;
				}
			}

			return *this;
		}

		void update(T &val, int index)
		{
			/* Update always involve updating sequence number, a way to tell that the
			 * cache line is hot.
			 */
			seq_no_ ++;

			items_[index].val = val;
			items_[index].is_avail = true;
			items_[index].seq_no = seq_no_;
		}

		int get_index(T &val)
		{
			int i;

			for (i = 0; i < n; i ++) {
				if (items_[i].val == val) {
					break;
				}
			}

			return i == n ? -1 : i;
		}

		T &get_val(int index)
		{
			return items_[index].val;
		}

	private:
		lru_cache_items<T> items_[n];
		uint32_t seq_no_;
		uint32_t index_;
};

int main()
{
	int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int p1 = 11;
	int p2 = 12;
	int u1 = 13;
	int u2 = 14;
	int i;
	lru_cache<int, 10> lru;

	for (i = 0; i < 10; i ++) {
		lru.push(a[i]);
	}

	lru.update(a[0], 0);
	lru.update(a[1], 1);
	lru.push(p1);
	lru.push(p2);

	for (i = 0; i < 10; i ++) {
		std::cout << "val: " << lru.get_val(i) << std::endl;
	}
}

