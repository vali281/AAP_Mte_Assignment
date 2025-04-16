// Solution for question 26
// Time complexity is O(n)
// Space complexity is O(1) respectively

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy;
    ListNode* slow = &dummy;

    // Move fast pointer n steps ahead
    for (int i = 0; i <= n; ++i) {
        fast = fast->next;
    }

    // Move both fast and slow pointers until fast reaches the end
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the nth node
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy.next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    head = removeNthFromEnd(head, 2);

    cout << "After removing 2nd from end: ";
    printList(head);

    return 0;
}
