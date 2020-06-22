/*
  fibonacci series:- 0 1 1 2 3 4 8 .....
  Given a number N. Find the Nth term in the fibonacci series 


*/

#include <iostream>
using namespace std;

int fib(int n){
    if(n==0 || n==1) return n;

    int f1 = fib(n-1);
    int f2 = fib(n-2);
    return f1+f2;
}
int main() {
    int n = 4;

    cout<<fib(n)<<endl;

}
