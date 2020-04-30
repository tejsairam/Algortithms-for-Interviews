// Implement Linear Search Recursively

#include <iostream>
using namespace std;

int linearSearch(int *arr,int i,int n,int key){
    // base case
    if(i == n) return -1;
    if(key == arr[i]) return i;

    return linearSearch(arr,i+1,n,key);
}

int main() {
    int key;
    cin>>key;

    int arr[10] = {1,5,3,4,9,810,100,99999,77777,226677};
    
    int n = 10;
    int i = 0;
    cout<<linearSearch(arr,i,n,key)<<endl;


}


// Implement Binary Search Recursively

#include <iostream>
using namespace std;

int binarySearch(int *arr,int start,int end,int key){
    //base case
    if(start > end) return -1;

    int mid = (start + end) / 2;

    if(arr[mid] == key) return mid;

    if(arr[mid] > key){
        return binarySearch(arr,start,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,end,key);
    }


}

int main() {
    int key;
    cin>>key;

    int arr[6] = {1,3,5,7,12,15};
    
    int n = 6;
    int i = 0;
    cout<<binarySearch(arr,i,n-1,key)<<endl;


}


