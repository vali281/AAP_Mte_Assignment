// Solution for question 28
// Solution for question: Implement two stacks in a single array
// the complexities are :
// Time Complexity: O(1)
// Space Complexity: O(n)

#include <iostream>
using namespace std;

class TwoStacks {
private:
    int *arr;
    int size;
    int top1, top2;

public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1; // Top of first stack
        top2 = size; // Top of second stack
    }

    // Function to push element into stack 1
    void push1(int x) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    // Function to push element into stack 2
    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    // Function to pop element from stack 1
    int pop1() {
        if (top1 == -1) {
            cout << "Stack 1 Underflow\n";
            return -1;
        } else {
            int popped = arr[top1];
            top1--;
            return popped;
        }
    }

    // Function to pop element from stack 2
    int pop2() {
        if (top2 == size) {
            cout << "Stack 2 Underflow\n";
            return -1;
        } else {
            int popped = arr[top2];
            top2++;
            return popped;
        }
    }

    // Function to display the first stack
    void displayStack1() {
        if (top1 == -1) {
            cout << "Stack 1 is empty\n";
            return;
        }
        for (int i = 0; i <= top1; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Function to display the second stack
    void displayStack2() {
        if (top2 == size) {
            cout << "Stack 2 is empty\n";
            return;
        }
        for (int i = size - 1; i >= top2; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    TwoStacks ts(10);

    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);

    cout << "Stack 1: ";
    ts.displayStack1();

    cout << "Stack 2: ";
    ts.displayStack2();

    cout << "Popped from Stack 1: " << ts.pop1() << endl;
    cout << "Popped from Stack 2: " << ts.pop2() << endl;

    cout << "Stack 1 after pop: ";
    ts.displayStack1();

    cout << "Stack 2 after pop: ";
    ts.displayStack2();

    return 0;
}
