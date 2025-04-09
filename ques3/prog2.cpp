// using prefix sum approach
// the time complexity is O(n) and space complexity is O(n)
#include <iostream>
using namespace std;
int equi(int arr[], int n){
    int Larr[n];
    int Rarr[n];
    Larr[0] = arr[0];
    Rarr[n - 1] = arr[n - 1]; 
    // Left prefix sum
    for(int i = 1; i < n; i++){
        Larr[i] = Larr[i-1] + arr[i];
    }
    for(int i = n-2; i >= 0; i--){
        Rarr[i] = Rarr[i+1] + arr[i];
    }
    // check for equilibrium index
    for(int i = 0; i < n; i++){
        if(Larr[i]==Rarr[i]) return i;
    }
    return -1;
}
int main(){
    int arr[] = {1 , 2 , 6 , 4 , 0 , -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int result = equi(arr, n);
    if (result != -1)
        cout << "Equilibrium index is: " << result << endl;
    else
        cout << "No equilibrium index found." << endl;
}