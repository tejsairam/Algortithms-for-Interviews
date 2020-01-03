#!/usr/bin/env python
# coding: utf-8

#  # Array and Maths 

# <p> C++ Vectors
# 
#    <li> Vectors contain contiguous elements stored as an array.</li>
#       Accessing members of a vector or appending elements can be done in constant time, 
#       whereas locating a specific value or inserting elements into the vector takes 
#       linear time.
# 
#    -- In simple word vector are Dynamic Array with more functionality.
# 
#    -- Vector Operators
#           
#           assign   - assign elements to a vector
#           at       -  returns an element at a specific location
#           back     - returns a reference to last element of a vector
#           begin    - returns an iterator to the beginning of the vector
#           capacity - returns the number of elements that the vector can hold
#           clear    - removes all elements from the vector
#           empty    - true if the vector has no elements
#           end      - returns an iterator just past the last element of a vector
#           erase    - removes element from a vector
#           front    - returns a reference to the first element of a vector
#           insert   - inserts elements into the vector
#           max_size - returns the maximum number of elements that the vector can hold
#           pop_back - removes the last element of a vector
#           push_back- add an element to the end of the vector
#           rbegin   - returns a reverse_iterator to the end of the vector
#           rend     - returns a reverse_iterator to the beginning of the vector
#           reserve  - sets the minimum capacity of the vector
#           resize   - change the size of the vector
#           size     - returns the number of items in the vector
#           swap     - swap the contents of one vector with another vector.
# 
#    </p>
# 

# # Q) Given an array of size N and it is a read only array. It contains elements      between 1 to N. All elements come once and only 1    element comes twice.Find the missing and repeated number ??
# 
# 
# 
# eg:- i/p --> [3 1,2,5,3]
#      so missing number=4 and repeating number is =3
#      
# 
# brute force solution :-  copy into different array and sort it and iterate over the array
#                           o(n) time complexity
#                           o(n) space complexity
#                           
# 
# optimised solution :-  
#                         
#                    sum(1,2,----,N) - sum(arr[0],arr[1],......,arr[N])  
#               
#                     [1 2 3 4 5]      -   [1 2 3 3 5]
#                     missing - repeated = x  -----------------------------(1)
#                     
#                     sum(1^2,2^2,-----N^2) - sum(arr[0]^2,arr[1]^2,......arr[N]^2)
#                     missing^2-repeated^2 = y ----------------------------(2)
#                     
#                     (2)/(1) =====>>> solving this we get missing + repeated = z ----------(3)
#                     
#                     solving the equations, we get repeated and missing numbers
#                     
#                     o(n) time complexity and no extra space

# In[ ]:


*function(code*/)
*Please(Note:)
There are certain problems which are asked in the interview to also check how you take care of overflows in your problem.
This is one of those problems.
Please take extra care to make sure that you are type-casting your ints to long properly and at all places. Try to verify if your solution works if number of elements is as large as 105*/

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long n = A.size();
    long long sum = 0;
    long long sum_sq = 0;
    
    for(long long i=0;i<n;i++){
        sum += (long long)A[i];
        sum_sq += (long long)A[i]*(long long)A[i];
    }
    
     long long diff = (n*(n+1)/2)-sum;
    
    long long diff2 = ((n*(n+1)*(2*n+1))/6)-sum_sq;
    
    long long SUM1 = diff2/diff;

    int repeat= (SUM1-diff)/2;
    
    int missing = (diff+SUM1)/2;
  
    vector<int> ans;
    
    ans.push_back(repeat);
    ans.push_back(missing);
    
    return ans;

}


# # Q) Given an array of size N. Return max value of | Arr[i] - Arr[j] |?
# 
#     eg: [ 0 -1  5  7  10 ]
#     
# In o(n) run through the array find minimum and in o(n) time run through array and find maximum and find      difference.
#  
# time complexity- o(n)
#      
#      10-(-1) = 11
# 

# # Q) Given an Array[N]. Find the max value of  | A[i] - A[j] | + | i - j | ???
#  
# The above approach will not work here
# 
# Because of modulus there are 4 possible combinations
# 
# A[i] - A[j]  + i - j  -->can be written as --->>>  (A[i] + i) - (A[j] + j)  --(1)
# 
# A[i] - A[j]  +  j - i -->can be written as --->>>  (A[i] - i) - (A[j] - j)  --(2)
# 
# A[j] - A[i]  +  i - j -->can be written as --->>>  (A[j] - j) - (A[i] - i)  --(3)
# 
# A[j] - A[i] +  j - i --> can be written as --->>>  (A[j] + j) - (A[i] + i)  --(4)
# 
# From (1) and (4) it can be seen as difference of sum of element and it's index      --> (A[i] + i) - (A[j] + j)
#                   --> max( (A[i] + i) ) - min( (A[j] + j) ) ------(I)
#                   
# From (2) and (3) it can be seen as difference of difference of element and it's index-> (A[i] - i) - (A[j] - j)
#                   --> max( (A[i] - i) ) - min( (A[j] - j) ) ------(II)
#          
#          
#          So, the answer will be max(I,II)
#  edge case is if we have only 1 element in the array so is depends on the question
#  
#  
# implementation -->
# 
# step 1:-  initialize max1 = min1 = A[0] + 0
#                      max2 = min2 = A[0] - 0
#            
# step 2:-  for i --> 1 to N-1
# 
#              int a = A[i] + i
#              max1 = max(a, max1)
#              min1 = min(a, min1)
#              
#              int b = A[i] - i
#              max2 = max(b, max2)
#              min2 = min(b, min2) 
#    
# step 3:-  return max( (max1-min1) , (max2-min2) )

#  # Q) There are N bars each of width 1 unit and lengths represented in array. When the rainfall happens water is going to be trapped. How manu units of water are going to be trapped?
#  
#  eg:- Arr: { 0  1  0  2  1  0  1  3  2  1  2  2  }   water trapped = 6 units
#  
# intution is -- if it all the water has to be trapped then towards the right the bar should be greater than the height and towards the left also the bar should be taller.
# if water is trapped then how much water??
# for each bar water trapped = min(maxleftbar,maxrightbar) - Arr[i]
# 
# code,
# 
# I) water_trapped = 0
# 
# II) for loop to iterate over the bars
# 
# III) if(maxleft and maxright > Arr[i])
# 
#       water_trapped += ( min(maxleftbar,maxrightbar) - Arr[i] )
#       
# time complexity -->
#     for every bar finding left max bar and right max bar it will o(n)
#         So,o(n^2) time complexity
#      
#      if we do precomputation to find left max bar and right max bar in constant time
#      
#      i.e
#      
#      max1 = max{ 0,1,.....n-1 }
#      
#      max { i-1,.....n-1 } = MAX( A[i-1], max1}   ---o(1) time complexity fro findings max bars in left nd right
#        
#        So, time complexity is 0(n)

# # Q) Given an unsorted Arr[N] Find the maximum difference between successive elements in sorted form???
# 
# eg: {1 10 5 }  --> { 1 5 10 } --->max gap= 5
# 
# brute force:
#    
#       sort it in o(nlogn) time and solve it
# 
# but i want to do in o(n) time ???
# 
# explanation:
# 
# N=6 
# 
# min=1 and max=16
# 
# No of gaps = N-1
# 
# gap = (max-min)/(N-1)
# 
# So, my answer will be >=gap
# 
# i.e answer will never be in [min, min+gap) , [min+gap, min+2*gap) , [min+2*gap, min+3*gap)
# 
# eg:-
# 
# given array { 7  39  31  4  1  91  87  89  55  51  59  }
# 
# max= 91 and min=1 and N=11
# 
# So, no.of gaps = 10
# 
# minimum possible answer of gap =91-1/11-1 = 9
# 
# So, the buckets that i have are: No of buckets = N with size 9
# [1,10) --> 7,4,
# [10,20), 
# [20,30)  
# [30,40) --> 39,31
# [40,50)  
# [50,60)-->51,55,59 
# [60,70)
# [70,80)
# [80,90)-->87,89
# [90,100)-->91
# 
# elements from the same buckets can never contribute to answer
# 
# Suppose if this bucket is sorted on its own then, [1,4,7] [31,39] [51,55,59] [87,89] [91]
# 
# then the only possible answer will be 31-7 or 51-39 or 87-59 or 91-89
# 
# So,for each bucket i need to track the minimum and maximum i.e for ith bucket find min of ith bucket and max of i-1 th bucket and keep calculating the difference. We can ignore the buckets that are empty.
# 
# 
# implementation:- 
# 
# There are N buckets therefore, we can have 2 arrays
# 
# int MAX[N] = - inf
# 
# int MIN[N] = + inf
# 
# MAX[i] & MIN[i] are the max and min elements in a bucket
# 
# suppose we are at element arr[i] how to check which bucket it belongs too??
# 
#        bucket = (arr[i] - MIN)/(gap+1) 
