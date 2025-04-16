// Solution for question 29
#include <iostream>
using namespace std;

bool isPalindrome(int num) {
    // Handle negative numbers and numbers ending with 0 but not 0 itself
    if (num < 0 || (num % 10 == 0 && num != 0)) {
        return false;
    }

    int reversed = 0;
    while (num > reversed) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }

    // When the number of digits is odd, reversed will have one extra digit
    return num == reversed || num == reversed / 10;
}

int main() {
    int num = 121;
    if (isPalindrome(num)) {
        cout << num << " is a palindrome.\n";
    } else {
        cout << num << " is not a palindrome.\n";
    }

    num = -121;
    if (isPalindrome(num)) {
        cout << num << " is a palindrome.\n";
    } else {
        cout << num << " is not a palindrome.\n";
    }

    num = 10;
    if (isPalindrome(num)) {
        cout << num << " is a palindrome.\n";
    } else {
        cout << num << " is not a palindrome.\n";
    }

    return 0;
}
