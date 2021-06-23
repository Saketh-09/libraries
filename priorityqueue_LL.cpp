//priority queue implementation using linked lists
#include<bits/stdc++.h>
using namespace std;
class pq {
    public:
    int data;
    int priority;
    pq *next;

    pq(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }


};
pq* newNode(int x, int p) {
    pq *node = new pq(x, p);
    return node;
}
pq *head = NULL;
void push(int x, int p) {
    pq *node = newNode(x, p);

    // check if head is null, if it is make head = newNode
    if (head == NULL) {
        head = node;
        return;
    }

    pq *temp = head;
    pq *prev = NULL;

    // search for first node having priority less than p
    while (temp != NULL && temp->priority > p) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        // no node with priority less than this node
        prev->next = node;
    } else {
        if (prev == NULL) {
            // all the nodes have priority less than p
            // add this node at the starting
            node->next = head;
            head = node;
        } else {
            // add this node before the node with priority less than p
            node->next = temp;
            prev->next = node;
        }
    }
}
int pop() {
    // highest priority element will be at head
    if (head != NULL) {
        int data = head->data;
        // removing the head
        head = head->next;
        return data;
    }
    return -1;
}
int peek() {
    //returning data in head of the linked list as it contains maximum priority element
    if (head != NULL) {
        return head->data;
    }
    return -1;
}
int main() {

    push(6, 3);
    cout<<peek()<<endl;
    push(2, 4);
    cout<<peek()<<endl;
    push(10, 2);
    pop();
    cout<<peek()<<endl;
    push(8, 6);
    cout<<pop()<<endl;
    cout<<pop()<<endl;
    cout<<peek()<<endl;

    return 0;
}
