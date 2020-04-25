/*
   -- Given a number n and position i we have to clear the last i bits

       starting mask shoukd have all 1's and left shit it by i no of places
       So, mask have i zeros at end and rest all 1's

       */

#include<iostream>
using namespace std;

int clearBits(int n, int i){
    int mask = ( -1 << i);

    return n & mask;
}

int clearRangeItoJ(int n, int i, int j){
    int ones = (~0);
    int a = ones << (j + 1);
    int b = ( 1 << i) -1;
    int mask = a|b;
    int ans = n & mask;
    return ans;
}

int main(){
    int n = 31;
    int i = 1;
    int j = 3;

   cout<<"clear last i bits: "<< clearBits(n,i)<<endl;

   cout<<"clear range i to j: "<<clearRangeItoJ(n,i,j)<<endl;
}
