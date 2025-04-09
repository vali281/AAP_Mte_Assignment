#include <iostream>
using namespace std;
int rangeSum(int arr[], int n, int L, int R){
    
    int sum = 0;
    int narr[n + 1];
    narr[0] = 0;
    for(int i = 0; i < n; i++){
        narr[i + 1] = narr [i] + arr[i];
    }
    sum = narr [R + 1] - narr[L];
    return sum;
}
int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int L = 1, R = 3;
    int result = rangeSum(arr, n, L, R);
    cout << "Sum of elements from index " << L << " to " << R << " is: " << result << endl;
}