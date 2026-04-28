class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        int i=0,j =1;
        int count =0;
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        while(j<n){
            vector<int>curr = arr[i];
            vector<int>nex = arr[j];
            int cs = curr[0];
            int ce = curr[1];
            int ns = nex[0];
            int ne = nex[1];

            if(ce<=ns){
                i=j;
                j++;
            }else if(ce<=ne){
                j++;
                count++;
            }else if(ce>ne){
                i=j;
                j++;
                count++;
            }
        }
        return count;

    }
};