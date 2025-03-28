//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &end) {
      vector<pair<int,int>>temp;
      int n = end.size();
     
      for(int i=0;i<n;i++){
         temp.push_back({end[i],start[i]});
         
      }
      sort(temp.begin(),temp.end());
      int ans=1,last = temp[0].first;
      for(int i=1;i<end.size();i++){
          if(last<temp[i].second){
              ans++;
              last = temp[i].first;
          }
      }
      return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends