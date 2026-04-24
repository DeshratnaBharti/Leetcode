// User function template for C++

class Solution {
  public:
    vector<int> prefixAvg(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<int>pre;
        int s =0;
        for(int i=0;i<n;i++){
            s = s + arr[i];
            pre.push_back(s/(i+1));
        }
        return pre;
    }
};