class Solution {
  public:
    int countFreq(vector<int>& arr, int t) {
        // code here
        int n = arr.size();
        int l =0,h =n-1;
        //lower bound
        int lb =n;
        while(l<=h){
            int mid = (l+h)/2;
            if(arr[mid]>= t){
                lb = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
         l= 0,h=n-1;
        //upper bond
       int up =n;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(arr[mid]>t){
                up = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return up  -lb;
    }
};
