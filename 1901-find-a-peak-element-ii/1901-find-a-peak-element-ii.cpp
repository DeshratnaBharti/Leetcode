class Solution {
public:
    int findmaxIndex(vector<vector<int>>& mat,int n,int m,int col){
        int maxVal = -1;
        int index = -1;
        for(int i=0;i<n;i++){
            if(mat[i][col]>maxVal){
                maxVal = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
       int n=mat.size();
       int m =mat[0].size();
       int l=0,h=m-1;
       while(l<=h){
           int mid = l+(h-l)/2;
           int maxRowindex = findmaxIndex(mat,m,n,mid);
           int left = mid-1 >=0 ? mat[maxRowindex][mid-1] : -1;
           int right = mid+1< m ?  mat[maxRowindex][mid+1] : -1;
           if(mat[ maxRowindex][mid]>left and mat[ maxRowindex][mid]>right){
            return{maxRowindex,mid};
           }else if(mat[ maxRowindex][mid]<left) h = mid;
           else l=mid+1;
       }
       return {-1,-1};
    }
};