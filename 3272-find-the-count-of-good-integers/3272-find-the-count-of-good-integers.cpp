class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> st;
        int d = (n + 1) / 2;
        long long start = pow(10, d - 1);
        long long end = pow(10, d) - 1;

        for (long long num = start; num <= end; num++) {
            string leftH = to_string(num);
            string full = "";

            if (n % 2 == 0) {
                string rightH = leftH;
                reverse(rightH.begin(), rightH.end());
                full = leftH + rightH;
            } else {
                string rightH = leftH.substr(0, d - 1);
                reverse(rightH.begin(), rightH.end());
                full = leftH + rightH;
            }

            long long number = stoll(full);
            if (number % k != 0) continue;

            // Sort the palindrome to avoid duplicates
            string sortedFull = full;
            sort(sortedFull.begin(), sortedFull.end());
            st.insert(sortedFull);
        }

        vector<long long> factorial(11, 1);
        for (int i = 1; i < 11; i++) {
            factorial[i] = factorial[i - 1] * i;
        }

        long long result = 0;
        for (const string& s : st) {
            vector<int> count(10, 0);
            for (const char& ch : s) {
                count[ch - '0']++;
            }

            int tD = s.length();
            int zeroCount = count[0];
            int nonZeroCount = tD - zeroCount;

            // Permutations, accounting for leading zeros
            long long perm = (nonZeroCount * factorial[tD - 1] );
            for (int i = 0; i < 10; i++) {
                perm /= factorial[count[i]];
            }

            result += perm;
        }
        return result;
    }
};
