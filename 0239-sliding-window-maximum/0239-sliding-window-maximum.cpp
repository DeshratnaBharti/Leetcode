class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n = nums.size();
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(dq.size()>0 and nums[i] > nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            while(dq.front()<(i-k+1)) dq.pop_front();
            if(i>=k-1) ans.push_back(nums[dq.front()]);
           
        }
        return ans;
    }
};