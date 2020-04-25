//Exponentiation or power using bitmasking i.e power(a,b)

#include <iostream>
using namespace std;

int powerOptimised(int a,int n) {
    int ans = 1;

    while(n>0){
        int last_bit = n&1;
        if(last_bit){
            ans = ans * a;
        }
        a = a * a; // square up
        n = n >> 1; // discard the last bit
    }
    return ans;
}
int main() {
    int a,n;
    cin>>a>>n;
    
    
    cout<<powerOptimised(a,n)<<endl;
    
    
    return 0;
}
