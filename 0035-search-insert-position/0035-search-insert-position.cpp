class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int n = arr.size();
        int low =0;
        int high = n-1;
        if(arr[high]<x) return high+1;
        if(arr[low]>x) return 0;
        int ans = -1;
        bool flag = false;
       while(low<= high ){
            int mid = (low +(high -low)/2);
            if(arr[mid] == x ){
                flag = true;
                ans = mid;
                break;
                
            }
            else if( arr[mid] < x ) low = mid +1;
            else  high = mid-1;
        }
        if( flag == false) ans = low;
        return ans;
    }
};