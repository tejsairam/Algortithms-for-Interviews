/*
   Given a brick wall 2 X N, and tiles of size 2 X 1, you have to find out the total no of ways 
   to arrange the tiles on the wall 
*/

#include <iostream>
using namespace std;

int numOfWays(int n){
    // base case
    if(n == 1 || n == 2) return n; 

    return numOfWays(n-1)+numOfWays(n-2);
}

int main() {
    
    int N;
    cin>>N;
    cout<<numOfWays(N)<<endl;
}
