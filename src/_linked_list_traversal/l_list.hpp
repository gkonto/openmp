#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
template<typename T>
class Lnode;

typedef void (*FOR_EVERY_FUN)(Lnode<int> &node, void *args);
typedef void (*FREE_FUN)(Lnode<int> &node);

template<typename T>
class Lnode {
	public:
		explicit Lnode(T val) : val_(val) {}
		Lnode<T> *addNode(T val) {
			next_ = new Lnode<T>(val);
			return next_;
		}

		~Lnode() {
			if (!next_) {
				delete next_;
			}
		}

		const T &data() const { return val_;}
		Lnode<T> *next() const { return next_; }

		void forNext(FOR_EVERY_FUN fn, void *args) {
			fn(*this, args);
			if (next_) {
				next_->forNext(fn, args);
			}
		}

	private:
		T val_;
		Lnode<T> *next_ = nullptr;
};


template<typename T>
class Llist {
	public:
		Llist(T val) {
			head_ = new Lnode<T>(val);
		}
		Lnode<T> *head() { return head_; }

		~Llist() {
			delete head_;
		}

		size_t size() const {
			Lnode<T> *node = head_;
			size_t size = 0;
			for (; node;) {
				++size;
				node = node->next();
			}
			return size;
		}

		void forEveryNode(FOR_EVERY_FUN fn, void *args) {
			head_->forNext(fn, args);
		}

	private:
		Lnode<T> *head_ = nullptr;
};

#endif

