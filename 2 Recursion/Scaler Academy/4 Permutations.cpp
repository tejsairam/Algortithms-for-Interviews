/*
   Given a string, find all the permutations of the string
   for time being, the given string will have only unique characters

   eg:- input:  "abc"
        permutations of abc are   abc
                                  acb

                                  bac
                                  bca

                                  cab
                                  cba
                                
        if you observe the permutations we can clearly see that every character has a chance
        of becoming the 1st character.

        Recursive assumption is for each character go and calculate the permutations of the rest of the characters

        What if characters are repeated then make a boolean of visited

*/



#include <iostream>
using namespace std;
//No repeatitions in characters
void permu(string str,string osf){
    if(str.size() == 0){
        cout<<osf<<endl;
        return;
    }

    for(int i=0;i<str.size();i++){
        char ch = str[i];
        ros = sts.substr(o,i) + str.substr(i+1);
        permu(str,osf+ch);
    }
}

// if characters are repeated -- but not optimised solution
//optimised solution swap nd then use recursion
void permu(string str,string osf){
    if(str.size() == 0){
        cout<<osf<<endl;
        return;
    }

    bool visited[26] = {0};
    for(int i=0;i<str.size();i++){
        char ch = str[i];
        if(visited[ch-'a'] == false){
        ros = sts.substr(o,i) + str.substr(i+1);
        visited[ch-'a'] = true;
        permu(str,osf+ch);
        }
    }
}
int main() {
    cout<<"Hello World!";
}
