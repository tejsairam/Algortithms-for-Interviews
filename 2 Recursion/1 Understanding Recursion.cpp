/*

Recursion is a method where solution depends on solution to smaller instances of the same problem

Parts of recursion: 1) figure out the base case
                    2) Assume sub problem can be solved automatically
                    3)recursive call i.e call ourselves

*/
#include <iostream>
using namespace std;

int fact(int n){
    //base case
    if(n == 0) return 1;

    int ans = n*fact(n-1);
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<fact(n)<<endl;
}
