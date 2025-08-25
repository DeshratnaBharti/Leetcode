class Solution {
public:
    bool isPalindrome(string s) {
        if(s==" ") return true;
        int low =0;
        int high=s.length()-1;
        while(low<high){
            if(!isalnum(s[low])){
                low++;
            }
            else if(!isalnum(s[high])){
                high--;
            }
            else if(tolower(s[low])!=tolower(s[high])){
              return false;  
            }
            else{ 
                low++;
                high--;

            }
        }
       
       return true;
    }
};