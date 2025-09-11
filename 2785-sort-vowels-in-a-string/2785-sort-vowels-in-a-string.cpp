class Solution {
public:
    bool isVowel(char x){
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I' or x=='O' or x=='U')return true;
        else return false;
    }
    string sortVowels(string s) {
        vector<int>v;
        for(auto x:s){
            if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I' or x=='O' or x=='U'){
               v.push_back(x);
            }
        }
        string t="";
        sort(v.begin(),v.end());
        for(int i=0;i<s.length();i++){
            if(!isVowel(s[i])){
              t += s[i];
            

            }else{
                t+=v.front();
                v.erase(v.begin(),v.begin()+1);
            }
        }
        return t;
        
    }
};