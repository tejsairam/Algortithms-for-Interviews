/* Given an array  say -n,
   Print all numbers from 1 to n in
     - Increasing order
     - Decreasing order
    
*/

#include <iostream>
using namespace std;

void inc(int n){
    //base case
     if(n == 0) return;

    inc(n-1);
    cout<<n<<" ";
    
}

void dec(int n){
    if(n == 0) return;

    cout<<n<<" ";
    dec(n-1);
}

int main() {
    int n = 5;

    cout<<"Increasing order array: "<<endl;
    inc(n);
    cout<<endl;
    cout<<"Decreasing array: "<<endl;
    dec(n);
}
