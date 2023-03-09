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
