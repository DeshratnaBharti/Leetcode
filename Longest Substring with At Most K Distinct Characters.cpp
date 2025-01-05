#include <bits/stdc++.h>
using namespace std;
int kDistinctChars(int k, string &s)
{
   int i=0,j=0,n = s.length();
     unordered_map<char,int>mp;
        int maxC = 0;
       
        while(j<n){
           
            mp[s[j]]++;
           
              while(mp.size()>k){
                mp[s[i]]--;

                if (mp[s[i]] == 0) {
                  mp.erase(s[i]);
                }
                i++;
              }
              maxC = max(maxC, j - i + 1);
              j++;
        }
        return maxC;
}
