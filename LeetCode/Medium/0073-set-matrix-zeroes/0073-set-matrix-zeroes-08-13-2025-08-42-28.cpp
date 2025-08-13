class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols =matrix[0].size();
        vector<int>m(rows,0);//m naam ka e vector baneye hai
        vector<int>n(cols,0);
         
         for(int i=0;i<rows;i++){
            for (int j=0 ;j<cols;j++){
                if(matrix[i][j]==0){
                    m[i]=1;
                    n[j]=1;

                }
            }
         }
          for(int i=0;i<rows;i++){
            for (int j=0 ;j<cols;j++){
                if (m[i] or n[j]) matrix[i][j]=0;
            }
          } 
         //
        
    }
};