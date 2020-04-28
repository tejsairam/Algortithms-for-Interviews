/*
  -- Multiply 2 Numbers using recursion without using '*'

  */

#include <iostream>
using namespace std;

//Multiply 2 Numbers using recursion without using '*'
int multi(int a,int b){
    //base case
    if(a == 0| b == 0) return 0;

     return (a + multi(a,b-1));


}

int mul(int a,int b){
    int m = multi(a,abs(b));
    if(b < 0) return -m;
    else
    return m;
}
int main() {
    int a,b;
    cin>>a>>b;
    cout<<mul(a,b)<<endl;
}
