class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.length();
        //string t = "";
        int i=0,j=0,l=0;
        while(j<n){
            while(j<n and s[j] ==' ') j++;
            if (j >= n) break;

            //int start = l;
            if(l!=0) s[l++] = ' ';
            int start = l;
            while(j<n and s[j]!= ' '){
                s[l++]=s[j++];
            }
            reverse(s.begin()+start,s.begin()+l);
           
        }
      
            s.resize(l);
            return s;
        
    }
};