// Solution for question 49
// Time complexity is O(m + n)
// Space complexity is O(1) respectively

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    if (!headA || !headB) return nullptr;

    ListNode* pointerA = headA;
    ListNode* pointerB = headB;

    // Traverse both lists. When a pointer reaches the end of one list, start from the beginning of the other list.
    while (pointerA != pointerB) {
        pointerA = (pointerA == nullptr) ? headB : pointerA->next;
        pointerB = (pointerB == nullptr) ? headA : pointerB->next;
    }
    
    return pointerA; // Either the intersection node or nullptr if no intersection
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating two linked lists with intersection
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode* intersection = new ListNode(8);
    headA->next->next = intersection;
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = intersection;

    ListNode* intersectionNode = getIntersectionNode(headA, headB);

    if (intersectionNode) {
        cout << "Intersection at node with value: " << intersectionNode->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}
