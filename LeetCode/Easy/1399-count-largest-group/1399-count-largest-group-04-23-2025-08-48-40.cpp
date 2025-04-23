#include <iostream>
#include <unordered_map>
#include <limits>

class Solution {
public:
    // Function to calculate sum of digits
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;  // Get last digit and add to sum
            num /= 10;        // Remove last digit
        }
        return sum;
    }

    int countLargestGroup(int n) {
        std::unordered_map<int, int> groupSizeMap;
        
        // Count occurrences of each sumOfDigits
        for (int i = 1; i <= n; i++) {
            groupSizeMap[sumOfDigits(i)]++;
        }

        // Find the largest group size
        int largestSize = 0;
        for (const auto& [key, size] : groupSizeMap) {
            largestSize = std::max(largestSize, size);
        }

        // Count how many groups have the largest size
        int largestGroupCount = 0;
        for (const auto& [key, size] : groupSizeMap) {
            if (size == largestSize) {
                largestGroupCount++;
            }
        }

        return largestGroupCount;
    }
};
