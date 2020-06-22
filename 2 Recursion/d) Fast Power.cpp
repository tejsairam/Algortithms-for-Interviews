// Given 2 numbers a and b, calculate power(a,b) efficiently

/* brute force solution

#include <iostream>
using namespace std;

int fastPower(int a,int b){
    //base case
    if(b == 0) return 1;

    
    return a*fastPower(a,b-1);

}

int main() {
    int a,b;
    cin>>a>>b;

    
    cout<<fastPower(a,b)<<endl;
}
*/

//Optimized Solution

#include <iostream>
using namespace std;

int fastPower(int a,int b){
    //base case
    if(b == 0) return 1;

    int smallAns = fastPower(a,b/2);
    smallAns *= smallAns;

    if(a & 1){
        return a * smallAns;
    }
    return smallAns;

}

int main() {
    int a,b;
    cin>>a>>b;

    
    cout<<fastPower(a,b)<<endl;
}
