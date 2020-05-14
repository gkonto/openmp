#ifndef LINKED_LIST
#define LINKED_LIST

struct Node {
    explicit Node(int data) : data_(data) {}
    ~Node() {
        if (next_) delete next_;
    }

    Node *next_;
    int data_;
};

extern Node *init_nodes(int num_of_nodes, int value);

#endif

