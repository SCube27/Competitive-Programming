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

    public:
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};

Node* solve(Node* num1, Node* num2) {
    Node* dummy = new Node(NULL); // Creating a dummy node to start the new LL to keep sum
    Node* curr = dummy; // Keeping a pointer current to iterate over this new LL

    Node* t1 = num1; // Keeping a pointer t1 to iterate over num1
    Node* t2 = num2; // Keeping a pointer t2 to iterate over num2

    int carry = 0; // Keeping a carry var to add-up carryover of current digits to next place
    while(t1 != NULL || t2 != NULL) { // Loop until both of the loops end
        int sum = carry; // keep sum as carry (Since after every iteration a carry will be left so add it up to sum)
        if(t1) sum += t1->data; // If first LL is not empty add its node data to sum
        if(t2) sum += t2->data; // IF second LL is not empty add its node data to sum

        Node* NewNode = new Node(sum%10); // Create a new node for the newly created list (add sum value to it)
        carry = sum/10; // Check if there's any carryover of current sum add it to carry

        curr->next = NewNode; // Connect the current node to this newly created node 
        curr = curr->next; // Move the pointer of new LL to this new node

        if(t1) t1 = t1->next; // If first LL is still not empty move its pointer to next node
        if(t2) t2 = t2->next; // Same for second LL
    }

    if(carry) { // At last check if there's any carry over left
        Node* NewNode = new Node(carry); // Then create a new node and add carryover to it
        curr->next = NewNode; // Connect the new node to LL
    }

    return dummy->next; // Return the next of dummy as from there the actual LL starts
}
