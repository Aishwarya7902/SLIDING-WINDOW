PROBLEM:https://leetcode.com/problems/get-equal-substrings-within-budget/

blog (best):https://leetcode.com/problems/get-equal-substrings-within-budget/solutions/392833/c-sliding-window-o-n-prefix-sum-o-nlogn-implementations/?orderBy=most_votes

/*
Observation
Since we need to find the maximum substring that can be replaced we can actually breakdown this problem to an array of integers 
that represent the replacement cost of s[i] to t[i] and then find the maximum length of continuous integers in that array whose sum <= maxCost.

eg:
s = "aabcd"
t = "zbdag"
The array to find the maximum length on comes out to [1,1,2,2,3].

This problem can now be solved in many ways, two of which are descibed below.
Somewhat similar to 209. Minimum Size Subarray Sum

Sliding window solution
In general a sliding window is when we keep increasing the size of the window by increasing the right end to fit our goal,
if it increases the goal we reduce the window by sliding the left end until it again fits the goal, this ensures that the maximum window size is attained.
Complexity
Time: O(n). Since each element is added and removed once at max.
Space: O(1). Since we get the elemets of sum array on the fly.
*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
      int st=0,end=0,sum=0;
       while(end<s.size()){
           sum+=abs(s[end]-t[end++]);
          // end++;
           if(sum>maxCost){
               sum-=abs(s[st]-t[st++]);
               //st++;
           }
       } 
       return end-st;  
    }
}; 
