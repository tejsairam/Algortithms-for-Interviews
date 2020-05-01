/*
   Given a string s,task is to find all
   subsequences of the string s

*/

#include <iostream>
using namespace std;

void subsequences(char *inp,char *out,int i,int j){
    //base case
    if(inp[i] == '\0'){
        out[j] = '\0';
        cout<<out<<","<<endl;
        return;
    }


    //recursive case
    // 1) include the current character
    out[j] = inp[i];
    subsequences(inp,out,i+1,j+1);
    // 2) exclude the currrent character
    subsequences(inp,out,i+1,j);
}

int main() {
    char inp[100];
    cin>>inp;

    char out[100];
    subsequences(inp,out,0,0);

    return 0;
}
