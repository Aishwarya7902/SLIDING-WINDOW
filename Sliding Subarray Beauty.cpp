class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n=nums.size();
        //observation is we need only -ve no...so make a vector to keep track of it
        vector<int> freq(51,0),ans;
        for(int i=0,j=0;j<n;j++){
            if(nums[j]<0)freq[abs(nums[j])]++; //if current element is -ve put in freq vector
            if(j-i+1>=k){ //if size hits.......check what is the xth element
                int cnt=0;
                for(int L=50;L>=1;L--){
                    cnt+=freq[L];
                    if(cnt>=x){
                        ans.push_back(-L);
                        break;
                    }
                    
                }
                if(cnt<x)ans.push_back(0); //if there are fewer than x negative integers put 0
                if(nums[i]<0){ //if starting element of window is -ve ....reduce its freq
                    freq[abs(nums[i])]--; 
                }
                i++; //slide the window
            }
        }
        return ans;
    }
};
