// the complexities are :
// Time Complexity: O(log(min(n, m)))
// Space Complexity: O(1)

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    if (A.size() > B.size())
        return findMedianSortedArrays(B, A);

    int x = A.size();
    int y = B.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxLeftX = (partitionX == 0) ? INT_MIN : A[partitionX - 1];
        int minRightX = (partitionX == x) ? INT_MAX : A[partitionX];

        int maxLeftY = (partitionY == 0) ? INT_MIN : B[partitionY - 1];
        int minRightY = (partitionY == y) ? INT_MAX : B[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0)
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            else
                return max(maxLeftX, maxLeftY);
        }
        else if (maxLeftX > minRightY)
            high = partitionX - 1;
        else
            low = partitionX + 1;
    }

    throw invalid_argument("Input arrays are not sorted");
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    cout << "Median: " << median << endl;

    return 0;
}
