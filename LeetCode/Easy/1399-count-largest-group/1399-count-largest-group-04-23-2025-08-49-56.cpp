#include <iostream>
#include <unordered_map>
#include <vector>

class Solution {
public:
    // Function to calculate sum of digits
    int sumOfDigits(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;  // Sum of digits
            num /= 10;
        }
        return sum;
    }

    int countLargestGroup(int n) {
        std::unordered_map<int, std::vector<int>> groupMap;

        // Creating groups based on sumOfDigits
        for (int i = 1; i <= n; i++) {
            groupMap[sumOfDigits(i)].push_back(i);
        }

        // Finding the largest group size
        int largestSize = 0;
        for (const auto& [key, group] : groupMap) {
            largestSize = std::max(largestSize, (int)group.size());
        }

        // Counting groups that have the largest size
        int largestGroupCount = 0;
        for (const auto& [key, group] : groupMap) {
            if ((int)group.size() == largestSize) {
                largestGroupCount++;
            }
        }

        return largestGroupCount;
    }
};

