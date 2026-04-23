class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int s = 0;
        int n = arr.size();
        for(int i=0;i<k;i++){
            s = s+arr[i];
        }
        int j = 0;
        int maxi = s;
       // s = s- arr[0];
        for(int i = k;i<n;i++){
            s = s+arr[i] - arr[j++];
            maxi = max(maxi,s);
        }
        return maxi;
    }
};