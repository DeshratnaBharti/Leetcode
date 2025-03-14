class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
       long long low = 1, high = *max_element(candies.begin(), candies.end()), result = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        long long totalChildren = 0;

        // Calculate how many children can be satisfied with 'mid' candies
        for (int candy : candies) {
            totalChildren += candy / mid;
        }

        // Check if it's feasible to satisfy at least 'k' children
        if (totalChildren >= k) {
            result = mid;  // Update result as we maximize candies
            low = mid + 1; // Try for larger mid
        } else {
            high = mid - 1; // Try for smaller mid
        }
    }

    return result; 
    }
};