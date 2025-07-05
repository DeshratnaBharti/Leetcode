class Solution {
public:
    void findlps(string pattern, vector<int>&lps){
        int M = pattern.length();
        int len =0;
        lps[0]=0;
        int i=1;
        while(i<M){
            if(pattern[i]==pattern[len]){
                len++;
                lps[i]=len;
                i++;
            }else{
                if(len !=0){
                    len = len-1;
                }else{
                    lps[i]=0;
                    i++;
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        string temp = s+"-"+r;
        vector<int>lps(temp.length(),0);
        findlps(temp,lps);
        int longestLPSLength = lps.back();
        string rem = r.substr(0,s.length()-longestLPSLength);
        return rem+s;
    }
};