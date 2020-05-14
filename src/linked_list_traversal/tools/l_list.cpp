#include "l_list.hpp"

Node *init_nodes(int num_of_nodes, int value) {
    Node *head = new Node(value);
    Node *temp = nullptr;

    Node *p = head;
    for (int i = 0; i < num_of_nodes; ++i) {
        temp =  new Node(value);
        p->next_ = temp;
        p = temp;
        p->data_ = value;
    }
    p->next_ = nullptr;
    return head;
}

