class Solution {
public:
   int colorTheGrid(int m, int n) {
        // Lambda function to check if a given state is valid
        auto isValidState = [&](int state) {
            int lastColor = -1;
            for (int i = 0; i < m; ++i) {
                int currentColor = state % 3;
                if (currentColor == lastColor) {
                    return false;
                }
                lastColor = currentColor;
                state /= 3;
            }
            return true;
        };

        // Lambda function to check if two states are valid neighbors
        auto areValidNeighbors = [&](int state1, int state2) {
            for (int i = 0; i < m; ++i) {
                if (state1 % 3 == state2 % 3) {
                    return false;
                }
                state1 /= 3;
                state2 /= 3;
            }
            return true;
        };

        // Modulo for calculating answer
        const int mod = 1e9 + 7;
        // Maximum number of states
        int maxStates = pow(3, m);

        // Set and vector to keep track of valid states and their count
        unordered_set<int> validStates;
        vector<int> stateCounts(maxStates);

        // Initialize valid states and their initial counts
        for (int i = 0; i < maxStates; ++i) {
            if (isValidState(i)) {
                validStates.insert(i);
                stateCounts[i] = 1;
            }
        }

        // Map to store neighboring valid states
        unordered_map<int, vector<int>> neighborStates;
        for (int i : validStates) {
            for (int j : validStates) {
                if (areValidNeighbors(i, j)) {
                    neighborStates[i].push_back(j);
                }
            }
        }

        // Iterate through columns
        for (int k = 1; k < n; ++k) {
            vector<int> newCounts(maxStates);
            // Update the count for each valid state based on its neighbors
            for (int i : validStates) {
                for (int j : neighborStates[i]) {
                    newCounts[i] = (newCounts[i] + stateCounts[j]) % mod;
                }
            }
            // Move newCounts to stateCounts for the next column
            stateCounts = move(newCounts);
        }

        // Calculate the final answer
        int answer = 0;
        for (int count : stateCounts) {
            answer = (answer + count) % mod;
        }

        return answer;
   }
};