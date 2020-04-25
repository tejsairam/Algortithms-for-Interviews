// Finding the number of set bits (3 methods)

#include <iostream>
using namespace std;

//1st method  O(logN)
int countBits(int n) {
    int ans = 0;
    while(n > 0) {
        ans = ans + (n & 1);
        n = n >> 1;
    }
    return ans;
}

//2nd method  O(no of set bits)
int countBitsFast(int n) {
    int ans = 0;
    while(n > 0) {
        n= n & (n - 1);
        ++ans;
    }
    return ans;
}



int main() {
    int n;
    cin>>n;
    cout << countBits(n) << endl;

     cout << countBitsFast(n) << endl;
     
//3rd method  inbuilt function to count set bits
     cout << __builtin_popcount(n) << endl;
    
}
