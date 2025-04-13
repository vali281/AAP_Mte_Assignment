#include <iostream>
using namespace std;
bool split(int arr[], int n){
    int* Lsum = new int[n];
    int* Rsum = new int[n];
    Lsum[0] = arr[0];
    Rsum[n - 1] = arr[n - 1];
    // calculate for left sum
    for(int i = 1; i < n; i++){
        Lsum[i] = Lsum[i - 1] + arr[i];
    }
    // calculate for right sum
    for(int i = n - 2; i >= 0; i--){
        Rsum[i] = Rsum[i + 1] + arr[i];
    }
    // check if there is point where Lsum and Rsum are equal
    for(int i = 0; i < n - 2; i++){
        // if found then return true
        if(Lsum[i] == Rsum[i+1]){
            delete[] Lsum;
            delete[] Rsum;
            return true;
        }
    }
    // doesnot found then return false
    return false;
}
int main(){
    int arr[] = {4, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool result = split(arr, n);
    if (result)
        cout << "Can be split" << endl;
    else
        cout << "Cannot split" << endl;
}