//{ Driver Code Starts
// Initial Template for C++



#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int pageFaults(int n, int c, int pages[]){
        unordered_set<int>s;
        list<int>LRU;
        int fault =0;
        for(int i=0;i<n;i++){
            int page = pages[i];
            if(s.find(page)==s.end()){
                if(LRU.size() < c){
                    LRU.push_back(page);
                    s.insert(page);
                }else{
                    int lru = LRU.front();
                    LRU.pop_front();
                    s.erase(lru);
                    LRU.push_back(page);
                    s.insert(page);
                }
                fault++;
            }else{
                LRU.remove(page);
                LRU.push_back(page);
            }
        }
        return fault;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends