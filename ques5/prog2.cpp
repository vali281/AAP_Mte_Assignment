// using sliding window approach
#include <iostream>
using namespace std;
int Msum(int arr[], int n, int k){
    int Msum = 0;
    // calculate sum for first k elements
    for(int i = 0; i < k; i++){
        Msum += arr[i];
    }
    // calculate new sum and update Msum if new sum is greater
    int sum = Msum;
    for(int i = 1; i <= n - k; i++){
        // cout<<sum<<endl; added to debug the code
        sum = sum + arr[k+i-1] - arr[i-1];
        if(sum > Msum) Msum = sum;
    }
    return Msum;
}
int main(){
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int result = Msum(arr, n , k);
    cout<<"The maximum sum of subarray of length "<< k <<" is: "<<result<<endl;
}