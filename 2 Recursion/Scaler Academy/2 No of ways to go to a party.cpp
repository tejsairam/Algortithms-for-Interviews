/* 
    There are N friends and they want to go to a party but there is a condition that
    each person can either go alone or they can go in a pair. In how many ways can 
    N friends go to a party ???

    eg:- N = 3 friends --> A B C

         (A) (B) (C)
         (AB) (C)
         (AC) (B)
         (BC) (A)        So, there are 4 different ways to go to party

         RECURENCE RELATION, 
         f(N) is the no of ways in which N friends can go to a party
         Suppose, there are 3 friends A B C
         Now, if A says he wants to go alone the other possible options for B C are (B) (C) and (BC) i.e.
         f(N - 1) is the no. of ways in which B C  can goto party. Therefore, f(N-1) contributes to f(N);

         if A says he wants to goto party in pair, then number of possible combinations are N-1 and the 
         remaining friends can go in f(N-2) ways to party.

         Hence recurence relation is -->  f(N) = f(N-1) + (N-1) * f(N-2)

         BASE CASE,
         if there is only 1 friend he can go in only 1 way i.e only alone
         if there are 2 friends there are only two ways i.e alone or in pair

*/




#include <iostream>
using namespace std;

int partyWays(int N){
    // base case
    if(N == 1) return 1;
    if(N == 2) return 2;

    return partyWays(N-1)+(N-1)*partyWays(N-2);
}

int main() {
    int N;
    cin >> N;

    cout<<partyWays(N)<<endl;
}
