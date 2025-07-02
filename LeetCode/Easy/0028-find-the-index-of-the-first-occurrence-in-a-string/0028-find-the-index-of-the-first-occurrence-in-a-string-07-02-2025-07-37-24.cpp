class Solution {
public:
void computeLPS(string &pat,vector<int>&LPS,int m){
       int len =0;
       LPS[0] =0;
       int i =1;
       while(i<m){
           if(pat[i] == pat[len]){
               len++;
               LPS[i] = len;
               i++;
           }
           else{
               if(len != 0){
                   len = LPS[len-1];
               }else{
                   LPS[i] =0;
                   i++;
               }
           }
       }
        
    }
    int strStr(string pat, string txt) {
        int n = txt.length();
       int m = pat.length();
       int result =-1;
       vector<int>LPS(m,0);
       computeLPS(pat,LPS,m);
       int i=0,j=0;
       while(i<n){
           if(txt[i] == pat[j]){
               i++;
               j++;
           }
           if(j==m){
              result = i-m+1;
              break;
           }else if(txt[i] != pat[j]){
               if(j!=0){
                   j = LPS[j-1];
               } else{
                   i++;
               } 
             
           }
       }
       return result;
    }
};