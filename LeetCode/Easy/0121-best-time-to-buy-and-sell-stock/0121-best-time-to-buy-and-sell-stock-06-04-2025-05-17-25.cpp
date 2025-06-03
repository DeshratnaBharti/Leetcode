class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxPr = 0;
        int miniPrice = arr[0]; 
        int n = arr.size();
        for(int i=1; i<n;i++){
           maxPr= max(maxPr,arr[i]-miniPrice);
           miniPrice =  min(arr[i],miniPrice);

        }
        return maxPr;

    }
};