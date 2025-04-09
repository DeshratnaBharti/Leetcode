class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Check if it's possible to make all elements equal to k
        for (int i = 0; i < n; i++) {
            if (nums[i] < k) {
                return -1; // Return -1 if any element is smaller than k
            }
        }

        // Step 2: Sort the array in descending order
        sort(nums.begin(), nums.end(), greater<int>());

        int count = 0; // To count the number of operations

        // Step 3: Process until the largest element becomes equal to k
        while (nums[0] > k) {
            // Find the largest value in the array (it is already sorted)
            int largest = nums[0];
            
            // Find the next largest distinct value (valid h)
            int h = k; // Initialize h as k
            for (int i = 1; i < n; i++) {
                if (nums[i] < largest) {
                    h = nums[i];
                    break;
                }
            }

            // Update all elements greater than h to h
            for (int i = 0; i < n; i++) {
                if (nums[i] > h) {
                    nums[i] = h;
                } else {
                    break; // Since the array is sorted, we can stop early
                }
            }

            count++; // Increment the operation count
        }

        // Step 4: Verify all elements are equal to k
        for (int i = 0; i < n; i++) {
            if (nums[i] != k) {
                return -1; // If not all elements are k, return -1
            }
        }

        return count; // Return the number of operations
    }
};
