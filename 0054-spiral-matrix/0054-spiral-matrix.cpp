class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int m = arr.size();
        int n= arr[0].size();
        int totalEle = m*n;
        int minr = 0,minc =0;
        int maxr = m-1,maxc=n-1;
        int count =0;
         vector<int> ans; 
        while(minr <= maxr and minc <= maxc){
            //when we go right
            for(int j= minc ;j<=maxc and count<totalEle; j++ ){
                ans.push_back(arr[minr][j]);
                count++;
            }
            minr++;
             //when we go down
            for(int j= minr ;j<=maxr and count<totalEle; j++ ){
                ans.push_back(arr[j][maxc]);
                count++;
            }
            maxc--;
             //when we go left
            for(int j= maxc ;j>=minc and count<totalEle; j-- ){
                ans.push_back(arr[maxr][j]);
                count++;
            }
            maxr--;
             //when we go up
            for(int j= maxr ;j>=minr and count<totalEle; j-- ){
                ans.push_back(arr[j][minc]);
                count++;
            }
            minc++;
        }
        return ans;
    }
};