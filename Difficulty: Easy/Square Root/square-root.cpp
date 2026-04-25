class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l =1;
        int  h= n;
        int ans= -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(mid>(n/mid)){
                
                 h = mid-1;
            }
            else{
             ans = mid;
                l = mid+1;
            }
        }
        return ans;
    }
};