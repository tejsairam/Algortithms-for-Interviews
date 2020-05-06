/* 
   You are given a number N, calculate the number of binary strings
   such that their length is N and they have no consecutive 1

   eg:- input = 3 ---> 0 1 1
        
        output:- 5 ---> 0 0 1, 0 1 0, 1 0 0, 1 0 1, 0 0 0

   for N = 1        N = 2           N = 3               N = 4
        0            0 1            0 0 1             0 0 0 0
        1            1 0            0 1 0             0 0 0 1
                     0 0            1 0 0             0 0 1 0
                                    1 0 1             0 1 0 0
                                    0 0 0             1 0 0 0
                                                      0 1 0 1
                                                      1 0 1 0
                                                      1 0 0 1
    ----------   ----------      ------------       ------------
    o/p:- 2           3               5                  8
    ----------   -----------     ------------       ------------

    if you observe the output it can be clearly seen that, output is of fibonacci series but with different base cases
     
                    fib(N) = fib(N - 1) + fib(N - 2)  --> recurence relation
    
*/

#include <iostream>
using namespace std;

int binaryStrings(int N){
    // base case
    if( N == 1 ) return 2;
    if( N == 2 ) return 3; 

    return binaryStrings(N - 1) + binaryStrings(N - 2);
}
int main() {
    int N;
    cin >> N;

    cout << binaryStrings( N ) << endl;

    return 0;
}
