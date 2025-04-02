class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long n = nums.size();
        long long sum=0,mSum=0;
        bool flag = false;
        for(long long i=0;i<n;i++){
            for(long long j =i+1;j<n;j++){
                for(long long k=j+1;k<n;k++){
                    sum =(nums[i]-nums[j])*nums[k];
                    if(sum<0){
                        sum=0;
                    }
                    mSum = max(sum,mSum);
                }
            }
        }
        return mSum;
    }
};