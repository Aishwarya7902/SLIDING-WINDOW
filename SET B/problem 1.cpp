PROBLEM:https://leetcode.com/problems/sliding-window-maximum/
VIDEO: https://www.youtube.com/watch?v=CZQGRp93K4k&t=907s


/*
SOME LEARNINGS AND PATTERN BUILDING STRATEGY
🔥🔥Sliding window minimum/maximum = monotonic queue.
What does Monoqueue do here:

It has three basic options:

push: push an element into the queue; O (1) (amortized)

pop: pop an element out of the queue; O(1) (pop = remove, it can't report this element)

max: report the max element in queue;O(1)

It takes only O(n) time to process a N-size sliding window minimum/maximum problem.

Note: different from a priority queue (which takes O(nlogk) to solve this problem), it doesn't pop the max element: It pops the first element (in original order) 
in queue.
*/

/*
tc:o(n)
sc:
*/


//fixed size sliding window
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0,j=0;
        vector<int> ans;
        deque<int>dq;
        while(j<nums.size()){
            //  ---------> we are storing in a deacreasing fashion
            //if upcoming element is less than back then only push in dq...else pop all smaller elements because we are storing in a deacreasing fashion
            //do some calculations 
            while(!dq.empty() && nums[j]>nums[dq.back()]){
                dq.pop_back();
            }
        
            dq.push_back(j);
            //while window size is less than...k ...j++;
            //condition not hit
            if(j-i+1<k)j++;
            else if(j-i+1==k){
                //when condition hits... ans <- cal
                //front element is max in dq of given window ..push in ans
                ans.push_back(nums[dq.front()]);
                //uneffect ith effect
                if(nums[i]==nums[dq.front()]){
                    dq.pop_front();
                }
                //slide window
                i++;
                j++;
            }

        }
        return ans;
    }
};
