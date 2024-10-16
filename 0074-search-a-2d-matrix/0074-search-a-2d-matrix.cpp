class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tgt) {
        
        int n = arr.size();
        int m = arr[0].size();
         int row_index, col_index,l=0,h=n*m-1,mid;
        while(l<=h){
            mid = l+(h-l)/2;
            row_index = mid/m;
            col_index = mid%m;
            if(arr[row_index][col_index]==tgt) return true;
            else if(arr[row_index][col_index]<tgt) l = mid + 1;
            else h=mid-1;
        }
return false;
    }
};