PROBLEM:
VIDEO:

/*
BRUTE FORCE

The naive approach will be to generate all subarrays of size K and find the sum of each subarray using iteration.
Time Complexity will be O(N*K).
There is no extra space used. Hence the auxiliary space complexity will be O(1).
*/
int calcSum(int arr[], int n, int k)
{
  
    // Loop to consider every
    // subarray of size K
    for (int i = 0; i <= n - k; i++) {
          
        // Initialize sum = 0
        int sum = 0;
  
        // Calculate sum of all elements
        // of current subarray
        for (int j = i; j < k + i; j++)
            sum += arr[j];
  
        // Print sum of each subarray
        cout << sum << " ";
    }
}
  
