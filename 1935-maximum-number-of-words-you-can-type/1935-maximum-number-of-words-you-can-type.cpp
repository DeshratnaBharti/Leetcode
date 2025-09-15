class Solution {
public:
    int canBeTypedWords(string t, string b) {
        unordered_set<char>st;
        for(auto &ch:b){
            st.insert(ch);
        }
        int count =0;
        bool canType = true;
        for(char &ch:t){
            if(ch==' '){
                if(canType) count++;
                 canType = true;
            }
           
            else if(st.find(ch)!=st.end()){
                   canType = false;
            }
        }
        if(canType) count++;
        return count;
    }
};