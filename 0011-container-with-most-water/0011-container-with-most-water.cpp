class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int i=0,j=n-1;
        int maxi = INT_MIN;
        while(i<=j){
            int l = j-i;
            int h = min(arr[i],arr[j]);
            maxi = max(maxi,l*h);
            if(arr[i]<arr[j]) i++;
            else j--;
        }
        return maxi;
        
    }
};