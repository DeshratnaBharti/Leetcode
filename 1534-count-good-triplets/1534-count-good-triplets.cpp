class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int n= arr.size();
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    if(abs(arr[i] - arr[j]) <= a and abs(arr[j] - arr[k]) <= b and (arr[i] - arr[k]) <= c) count++;
                }
            }
        }
        return count;
    }
};