class Solution {
public:
    int m,n;
    bool solve(vector<vector<char>>& board,int i,int j,int wi, string &word){
        if(wi == word.length()) return true;
        if(i<0 or j<0 or i>=m or j>=n or board[i][j]=='#') return false;
        if(board[i][j] != word[wi]) return false;
        
        char temp = board[i][j];
       board[i][j] = '#';
        
        if(solve(board,i-1,j,wi+1,word) 
           or solve(board,i,j+1,wi+1,word)
           or solve(board,i+1,j,wi+1,word) or
           solve(board,i,j-1,wi+1,word)){ return true;}
        
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] and solve(board,i,j,0,word)) return true;
            }
        }
        return false;
    }
};