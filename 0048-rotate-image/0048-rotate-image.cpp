class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n = arr.size();
        for(int i =0;i<n;i++){
            for(int j =0;j<=i;j++){
                 swap(arr[i][j],arr[j][i]);
                
            
            }  
        }
            for(int k=0;k<n;k++){
                int i=0;
                int j=n-1;
                while(i<=j){
                    int temp = arr[k][i];
                        arr[k][i]= arr[k][j];
                        arr[k][j]=temp;
                    i++;
                    j--;
                }
            }
        
        return;
    }
};