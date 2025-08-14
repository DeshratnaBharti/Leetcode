class Solution {
public:
    string largestGoodInteger(string num) {
        char maxC=' ';
        for(int i=2;i<num.length();i++){
             if(num[i]==num[i-2] and num[i]==num[i-1]){
                maxC = max(maxC,num[i]);
             }
        }
        if(maxC==' ') return "";
        return string(3,maxC);
    }
};