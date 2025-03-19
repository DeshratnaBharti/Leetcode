//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int n;
    int t[1001][201][2];
    int f(int ind,int mode, int k,vector<int>& arr){
        if(ind==n) return 0;
        if(k==0) return 0;
        //int take=0,not_Take=0;
        if (t[ind][k][mode] != -1)  // If already computed
        return t[ind][k][mode];
        if(mode==0){//buy
           int  take = f(ind+1,!mode,k,arr)-arr[ind];
            int not_Take = f(ind+1,mode,k,arr);
            return t[ind][k][mode]=max(take,not_Take);
        }
        else{//sell
            return t[ind][k][mode]= max(f(ind+1,!mode,k-1,arr)+arr[ind], f(ind+1,mode,k,arr));
        }
    }
    int maxProfit(vector<int>& arr, int k) {
        // code here
          memset(t, -1, sizeof(t));
        n = arr.size();
        return f(0,0,k,arr);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends