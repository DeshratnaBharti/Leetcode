class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end()); // poori string reverse
        int n = s.size();
        int i = 0, j = 0;
        while(i < n){
            while(i < n && s[i] == ' ') i++; 
            int start = j;
            while(i < n && s[i] != ' '){
                s[j++] = s[i++];
            }
            if(start < j){ 
                reverse(s.begin()+start, s.begin()+j); 
                if(j < n) s[j++] = ' '; 
            }
        }
        if(j > 0 && s[j-1] == ' ') j--; 
        s.resize(j);
        return s;
    }
};
