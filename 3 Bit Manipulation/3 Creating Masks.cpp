/* --Question is to find whethre given number N is odd or even??
         Brute Force:- For this problem instead of doing N%2 ==0 it is even else odd

         optimised sol'n:-  5 = 1 0 1
                      if last bit = 1 then it is odd

                      This is because is 1 0 1 exept last digit rest all contribute to 2 power something while 
                      last digit is 2 power 0 which is 1

                      N = 5 & 1
                        == 1 odd
                        == 0 even
  -- Question is to find ith bit from right
          For this we should create a mask i.e.
           N = 5     ==    0 0 1 0 1
           i = 2     ==    0 0 1 0 0
           if greater than 0 that particular bit is set else not set

           To create mask left shift it 
           i(N & (1 << i))
           
  -- Set ith bit
          create a msk and perform bitwise OR operation to set a particular bit

  -- Clear ith bit
          Create a mask with ith place 0 and all other bits as 1
          first create a normal mask and then neagate it

*/

#include<iostream>
using namespace std;

bool isOdd(int n){
    return ( n & 1 );
}

int getBit(int n,int i){
    int mask = 1 << i;
    int bit = (n & mask) > 0 ? 1 : 0;

    return bit;
}

int setBit(int n,int i){
    int mask = 1 << i;
    int ans = n | mask;

    return ans;

}

void clearBit(int &n,int i){
    int mask = ~(1 << i);
    n = n & mask;
}

void updateBit(int &n,int i,int v){ 
    // to update a particular bit with v clear that bit and do OR operation with mask
    int mask = ~(1 << i);
    int cleared_n = n & mask;
    n = cleared_n | (v << i); 

}
int main(){
    int n = 5;
    int i;
    cin>>i;
    cout<<"Odd or Not : "<<isOdd(n)<<endl;
    cout<<"Get bit : "<<getBit(n,i)<<endl;
    n = setBit(n,i);
    cout<<"After setting bit : "<<n<<endl;

    clearBit(n,i);
    cout<<"After clearing the bit: "<<n<<endl;

    updateBit(n, 4, 1);
    updateBit(n, 2, 0);
    cout<<"After updating bits: "<<n<<endl;
}
