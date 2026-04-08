class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int s =0;
        int n = arr.size();
        int i=0,j=0;
        while(j<n){
             s = s+ arr[j++];
             
             while(s>target and i<j){
                 s = s- arr[i++];
             }
             if(s==target){
                 return {i+1,j};
             }
        }
        return {-1};
    }
};