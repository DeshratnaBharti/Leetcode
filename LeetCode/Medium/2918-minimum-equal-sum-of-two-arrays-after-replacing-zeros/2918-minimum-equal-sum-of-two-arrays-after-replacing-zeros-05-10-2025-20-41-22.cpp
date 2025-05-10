class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int m= nums1.size();
        int n = nums2.size();
        int sum1=0,zero1=0;

        for(int i=0;i<m;i++){
            sum1+=nums1[i];
            if(nums1[i]==0) zero1++;
        }
        int sum2=0,zero2=0;

        for(int i=0;i<n;i++){
            sum2+=nums2[i];
            if(nums2[i]==0) zero2++;
        }
        int sumNums1=sum1+ zero1,sumNums2=sum2+ zero2;
        if(sumNums1<sumNums2 and  zero1==0)return -1;
        if(sumNums2<sumNums1 and  zero2==0)return -1; 
        return max(sumNums1,sumNums2);

    }
};