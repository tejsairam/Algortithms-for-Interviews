/* 
    Subsequences
   "abc" -> " ",  "a",  "b",  "c",  "ab",  "ac",  "bc",  "abc"

   for a set of size N, no of subsets is pow(2,N)
   for each character we can choos to append or to not append

   " "    ------>   append a = "a"    ------>append b = "ab"       --------->append c = "abc"
                                                                   --->don't append c = "ab"

                                      ---> don't append b = "a"           ------> append c = "ac"
                                                                         -->don't append c = "a"
   
   " "   ---> don't append a = " "     ------>append b = "b"         ------->append c = "bc"
                                                                    -->don't append c = "b"

                                       ---> don't append b = " "           ------> append c = "c"
                                                                          -->don't append c = " "
                                                                        
*/


#include <iostream>
using namespace std;

void subsequence(string str, string output_so_far/*osf*/){
    //base case
    if(str.size() == 0){
        cout << output_so_far << endl;
        return;
    }

    char = str[0];
    rest_of_str = str.substr(1);// str = abcd then str.substr(1) = bcd
    subsequence(rest_of_str,output_so_far + ch);
    subsequence(rest_of_str,output_so_far)

    /*
        we took (str,osf) as input for the function
        str = "abc"   -->  (bc , a)        --> (c , ab)   ===>(" " , abc)
                                                          ===>(" " , ab)
                                           --> (c , a)    ===>(" " , ac)
                                                          ===>(" " , a)
                      -->  (bc , " ")      --> (c , b)    ===>(" " , bc)
                                                          ===>(" " , b)
                                           --> (c , " ")  ===>(" " , c)
                                                          ===>(" " , " ")

    */
                    
                              
}
int main() {
    string str;
    cin>>str;

    subsequences(str," ");
    return 0;
}
