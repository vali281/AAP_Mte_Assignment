// Solution for question 22
// the complexities are :
// Time Complexity: O(1)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    int num = 16;
    if (isPowerOfTwo(num)) {
        cout << num << " is a power of two" << endl;
    } else {
        cout << num << " is not a power of two" << endl;
    }
    return 0;
}