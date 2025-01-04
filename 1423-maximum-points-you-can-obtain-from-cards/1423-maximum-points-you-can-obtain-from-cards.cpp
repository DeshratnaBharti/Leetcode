class Solution {
public:
    int maxScore(vector<int>& arr, int k) {
        int n = arr.size();
        int sum =0;
        for(int i=0;i<k;i++){
            sum += arr[i];

        }
        int maxSum = sum;
        for(int i=k-1;i>=0;i--){
            sum -= arr[i];
            sum += arr[n-k+i];//piche se add kar rahe hai
            maxSum = max(sum,maxSum);
        }
        return maxSum;
    }
};