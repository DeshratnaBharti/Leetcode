//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
         vector<pair<int,int>>arr;
         int n= wt.size();
         for(int i=0;i<n;i++){
             arr.push_back({val[i],wt[i]});
         }
         sort(arr.begin(),arr.end(),[](auto &p1, auto &p2){
        double r1 =(p1.first*1.0)/(p1.second*1.0);
        double r2 = (p2.first*1.0)/(p2.second*1.0);
        return r1>r2;
    });
         double res = 0;
         for(int i=0;i<n;i++){
             if(arr[i].second<= capacity){
                 res += arr[i].first;
                 capacity -= arr[i].second;
                 
             }else{
                 res += ((arr[i].first*1.0)/(arr[i].second *1.0))*capacity;
                 capacity =0;
                 break;
             }
         }
         return res;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends