class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int count = 0;

        while (!nums.empty()) {
            std::unordered_map<int, int> freqMap;

            // Populate the map with frequency counts
            for (int num : nums) {
                freqMap[num]++;
            }

            // Check if all elements are distinct
            if (freqMap.size() == nums.size()) {
                break; // All elements are distinct, exit the loop
            }

            // If the array has fewer than 3 elements, remove all
            if (nums.size() < 3) {
                nums.erase(nums.begin(), nums.end());
            } else {
                // Remove the first three elements
                nums.erase(nums.begin(), nums.begin() + 3);
            }

            count++;
        }

        return count;
    }
};
