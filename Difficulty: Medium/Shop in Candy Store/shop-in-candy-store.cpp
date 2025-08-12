class Solution {
public:
    vector<int> minMaxCandy(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int sumMin = 0, sumMax = 0;
        
        // Minimum cost calculation
        int i = 0, j = n - 1;
        while (i <= j) {
            sumMin += arr[i]; // buy cheapest
            i++;
            j -= k; // take k most expensive free
        }
        
        // Maximum cost calculation
        i = 0, j = n - 1;
        while (i <= j) {
            sumMax += arr[j]; // buy most expensive
            j--;
            i += k; // take k cheapest free
        }
        
        return {sumMin, sumMax};
    }
};
