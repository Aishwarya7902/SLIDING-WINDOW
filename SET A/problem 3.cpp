problem:
video:

/*
brute force
*/

/*
optimisation
tc:o(n)
sc:o(1)
*/

#include <bits/stdc++.h>
using namespace std;

bool checkSubarraySum(int arr[], int N,int K, int givenSum)
{
        // code here 
       int i=0,j=0;
      int sum=0;
       
       while(j<N){
           sum+=arr[j];
           if(j-i+1<K)j++;
           else if(j-i+1==K && sum==givenSum){
               // ans<--cal
               return true;
           }
           else{
               sum-=arr[i];
               i++;
               j++;
           }
       }
       return false;
        
    }
int main() {
   int arr[] = {1, 4, 2, 10, 2, 3, 1, 0, 20};
       int  k = 3, sum = 6;
       int n = sizeof(arr) / sizeof(arr[0]);
	cout<<checkSubarraySum(arr,n,k,sum);
	return 0;
}
