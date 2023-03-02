PROBLEM:https://practice.geeksforgeeks.org/problems/count-the-number-of-subarrays/1
VIDEO :https://drive.google.com/file/d/1966v9aT2tkomLaxdk7oIVrwvwngQAxwW/view
/*
brute force
generate all subarryas and check if sum is in given range
tc:o(n^2)
sc:o(1)
*/

/*
optimisation using sliding window
tc:o(n)
sc:o(1)
*/

class Solution {
  public:
    
    long long helpCount(int N,vector<int>&arr,long long x)
    {
       long long sum=0;
       long long ans=0;
       long long left=0,right;
       for(right=0;right<N;right++){
           sum+=arr[right];
           while(sum>x){
               sum-=arr[left];
               left++;
           }
           ans+=right-left+1;
       }
       return ans;
       
    }
    long long countSubarray(int N,vector<int>&arr,long long L,long long R) {
        // code here
        /*
        this can be simply done  by another medium level question which is 
        count of subarrays having sum less than  k....only modification we will
        do is that we will include subarrays having sum<=k
        
        for finding out the count of subarrays in given range ..we can simply use
        above question
        ----------l---------r----------
        -------l-1<
        --------------------r<
        if we subtract <r and <(l-1) we will be left with the given range which
        is our ans
        */
        long long ans1=helpCount(N,arr,L-1);
        long long ans2=helpCount(N,arr,R);
        return ans2-ans1;
        
    }
};

