class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.length();
        int low,high;
        int si = 0;
       int len =1;
        for(int i=1;i<n;i++){
            //even case
            low = i;
            high = i-1;
            while(low>=0 and high < n and s[low] == s[high]){
                if(high - low +1>len){
                    si =low;
                    len = high -low +1;
                }
                low--;high++;
            }
            //odd case 
            low = i-1;
            high =i+1;
            while(low >=0 and high <n and s[low] == s[high]){
                if(high-low+1 > len ){
                    si = low;
                    len = high-low +1;
                }
                low--;high++;
            }
        }
        return s.substr(si,len);
    }
};