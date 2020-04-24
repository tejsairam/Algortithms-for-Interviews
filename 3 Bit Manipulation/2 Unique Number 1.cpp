// Unique Number 2N+1
/* 
     Given an array of integers which contains every element even number of times and 1 element 
    occuring odd number of times. Find the element occuring odd number of times? 
                   eg:- input:- 3 2 3 5 6 5 2
                        output:- 6

*/

#include <iostream>
using namespace std;
int main() {
   int n;
   cin>>n;

   int num;
   int ans = 0;
   for(int i=0;i<n;i++){
       cin>>num;
       ans = ans ^ num;
   }

   cout<<ans<<endl;
}
