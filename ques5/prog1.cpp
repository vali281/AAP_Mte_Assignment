// brutrforce approach
#include <iostream>
#include <climits>
using namespace std;
int Msum(int arr[], int n, int k){
    int MaxSum = 0;
    for(int i = 0; i < k; i++){
        MaxSum +=arr[i];
    }
    for(int i = 1; i <= n - k; i++){
        int sum = 0;
        for(int j = i; j < i + k; j++){
            sum +=arr[j];
        }
        if(sum > MaxSum) MaxSum = sum;
    }
    return MaxSum;
    
}
int main(){
    int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    int result = Msum(arr, n , k);
    cout<<"The maximum sum of subarray of length "<< k <<" is: "<<result<<endl;
}