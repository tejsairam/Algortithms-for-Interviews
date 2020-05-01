#include <iostream>
using namespace std;

void towerOfHanoi(int n,char src,char dest,char helper){
    //base case
    if(n == 0) return;

    //rec case
    //first step is to move N-1 disks from src to helper
    towerOfHanoi(n-1,src,helper,dest);

    cout<<"Move "<<n<<" disk from "<<src<<" to "<<dest<<endl;

    towerOfHanoi(n-1,helper,dest,src);
}

int main() {
    int n;
    cin>>n;
    towerOfHanoi(n,'A','C','B');

    return 0;
}
