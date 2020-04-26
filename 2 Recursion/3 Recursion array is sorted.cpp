//Given an array, check if it sorted or not

#include <iostream>
using namespace std;

bool isSorted(int *arr,int n){
    if(n == 1){
        return true;
    }

    if(arr[0] < arr[1] && isSorted(arr+1,n-1)){
        return true;
    }

    return false;
}

int main() {
    int n = 5;
    int arr[] = {1,2,3,4,5};

    if(isSorted(arr,n)){
        cout<<"Array is sorted"<<endl;
    }
    else{
        cout<<"Not Sorted"<<endl;
    }


}
