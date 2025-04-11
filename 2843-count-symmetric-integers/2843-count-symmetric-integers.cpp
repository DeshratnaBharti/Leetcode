class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            int leftS=0,rightS=0;
          
            string s = to_string(i);
            int n = s.length();
            if(n%2 !=0) continue;
            for(int i=0;i<n/2;i++){
                leftS += s[i]-'0';
            }
            for(int j=n/2;j<n;j++){
                rightS += s[j]-'0';
            }
            if(leftS ==rightS) count++;
        }
        return count;
    }
};