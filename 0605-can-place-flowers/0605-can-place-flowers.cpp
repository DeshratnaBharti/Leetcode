class Solution {
public:
    bool canPlaceFlowers(vector<int>& arr, int k) {
        int n = arr.size();
        for(int i=0; i<n && k>0; i++){
            if(arr[i] == 0){
                // boundary handle
                if((i == 0 || arr[i-1] == 0) && (i == n-1 || arr[i+1] == 0)){
                    arr[i] = 1;
                    k--;
                }
            }
        }
        if(k == 0) return true;
        return false;
    }
};
