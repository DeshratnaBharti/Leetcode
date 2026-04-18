class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n = s.length();
        string t = "";
        int i=0,j=0;
        while(j<n){
            while(j<n and s[j] ==' ') j++;
            i = j;
            while(j<n and s[j]!= ' ')j++;
            reverse(s.begin()+i,s.begin()+j);
            if(!t.empty() ) t += " ";
            t += s.substr(i,j-i);
            
            //j++;
        }
        //reverse(s.begin()+i,s.begin()+j);
           // t += s.substr(i,j-i+1);
           while(!t.empty() and t.back()==' ') t.pop_back();
            return t;
        
    }
};