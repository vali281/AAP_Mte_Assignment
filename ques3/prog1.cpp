// using brute force approach
// the time complexity is O(n^2) and space complexity is O(1)
#include <iostream>
using namespace std;
int equi(int arr[], int n){

    for(int i = 0; i < n;  i++){
        int Lsum = 0;
        int Rsum = 0;
        for(int j = 0; j < i ; j++){
                Lsum += arr[j];
            }
        for(int j =i + 1; j < n; j++){
                Rsum += arr[j];
            }
        if(Lsum == Rsum) return i;
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