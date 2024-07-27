#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseListIterative(ListNode* head) {
        cout << "Dry Run Once";
        if(head == NULL || head->next == NULL) return head;

        ListNode* back = NULL;
        ListNode* temp = head;
        ListNode* forw = temp->next;

        while(temp != NULL) {
            temp->next = back;
            back = temp;
            temp = forw;
            if(temp != NULL) forw = forw->next; // if temp is already null at this point no need to move ahead
        }
        return back;
    }

    ListNode* reverseListRecursive(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* newHead = reverseListRecursive(head->next); // this gives us a new reversed list till that part
        ListNode* front = head->next; 
        front->next = head;
        head->next = NULL;
        return newHead;
    }
};

// In the recursive form, after a newhead is returned the head is supposed to be the last node of that new list
// The returned newHead's list's last node points NULL and also it is pointed by head
// Our job is to include the head to this newhead's list
// since head's next points the last node we use it to call it as front
// from pointing to NULL we point front to head and update the head's next to NULL thus including head in this new list