PROBLEM:https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1?utm_source=gfg&utm_medium=article&utm_campaign=bottom_sticky_on_article

VIDEO:

/*
brute force
generate all subarrays....if length==k update ans with max of sum and ans
*/

/*
optimisation 
using sliding window
tc:o(n)
sc:o(1)
*/

class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &arr , int N){
        // code here 
       int i=0,j=0;
       long sum=0;
       long ans=0;
       while(j<N){
           sum+=arr[j];
           if(j-i+1<K)j++;
           else if(j-i+1==K){
               // ans<--cal
               ans=max(ans,sum);
               sum-=arr[i];
               i++;
               j++;
           }
       }
       return ans;
        
    }
};
