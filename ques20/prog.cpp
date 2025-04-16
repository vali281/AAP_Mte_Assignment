// the complexities are :
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
using namespace std;

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) return 1;
    int total = 10, uniqueDigits = 9, available = 9;

    for (int i = 2; i <= n && available > 0; i++) {
        uniqueDigits *= available;
        total += uniqueDigits;
        available--;
    }

    return total;
}

int main() {
    int n = 2;
    cout << "Count of numbers with unique digits for n = " << n << ": "
         << countNumbersWithUniqueDigits(n) << endl;
    return 0;
}
