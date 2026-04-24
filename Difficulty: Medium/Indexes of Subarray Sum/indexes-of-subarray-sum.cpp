class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int t) {
        // code here
        int n = arr.size();
        int i=0,j=0,s=0;
        while(j<n){
            s = s + arr[j];
            while(i<=j and s>t){
                s = s- arr[i];
                i++;
            }
            if(s==t) return {i+1,j+1};
            j++;
        }
        return {-1};
    }
};