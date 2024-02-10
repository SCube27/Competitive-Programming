#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    public:
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* OddEvenList(Node* head) {
    Node* odd = head; // Since the head is on 1st index which is odd (odd pointer)
    Node* even = head->next; // The next node will be on 2nd index so even (even pointer)
    Node* evenHead = head->next; // Memoizing for later connecting with odd part

    while(even != NULL && even->next != NULL) { // Checked even as odd won't cross before even (even will end first)
        odd->next = odd->next->next; // Connecting next of odd with next odd index nodes (1st->next->next = 3rd)
        even->next = even->next->next; // Same for even (2nd->next->next = 4th)

        odd = odd->next; // Move odd to next odd index
        even = even->next; // Move even to next even index
    }
    odd->next = evenHead; // Finally connect the chain of odd nodes to head of evenchain that we memoized

    return head;
}
