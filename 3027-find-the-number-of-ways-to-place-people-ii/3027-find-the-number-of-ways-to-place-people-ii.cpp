class Solution {
public:
    int numberOfPairs(vector<vector<int>>& arr) {
        int n = arr.size();
        int res =0;
        auto l = [](auto a1,auto a2){
            if(a1[0]==a2[0]){
                return a1[1]>a2[1];
            }
            return a1[0]<a2[0];
        };
        sort(arr.begin(),arr.end(),l);
        for(int i=0;i<n;i++){
            int x1=arr[i][0];
            int y1 = arr[i][1];
            int maxY = INT_MIN;
            for(int  j=i+1;j<n;j++){
                int x2 = arr[j][0];
                int y2 = arr[j][1];
                if(y2>y1)continue;
                if(y2>maxY){
                    res++;
                    maxY = y2;
                }  
            } 
                     
        }
        return res;
    }
};