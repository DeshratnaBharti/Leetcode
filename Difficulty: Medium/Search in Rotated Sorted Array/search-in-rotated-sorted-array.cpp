class Solution {
  public:
    int search(vector<int>& arr, int t) {
        // Code Here
        int n = arr.size();
        int l =0,h = n-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid]==t) return mid;
            if(arr[l]<=arr[mid]){//left wala sorted
               if(arr[l]<=t and t <arr[mid]) h = mid-1;
                else l = mid+1;
                 
            }else{
                if(arr[mid]<t and t<=arr[h]){
                    l = mid+1;
                }
                else {
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};