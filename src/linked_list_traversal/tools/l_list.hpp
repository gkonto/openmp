#ifndef LINKED_LIST
#define LINKED_LIST

struct Node {
    explicit Node(int data) : data_(data) {}
    ~Node() {
        if (next_) delete next_;
    }

    Node *next_ = nullptr;
    int data_ = 0;
};

extern Node *init_nodes(int num_of_nodes, int value);

#endif

