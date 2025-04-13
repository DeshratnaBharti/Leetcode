class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long a, long long b, long long MOD) {
        if (b == 0) return 1;

        long long half = power(a, b / 2, MOD);
        long long result = (half * half) % MOD;

        if (b % 2 == 1) {
            result = (result * a) % MOD;
        }
        return result;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;  // Number of even-indexed positions
        long long oddCount = n / 2;         // Number of odd-indexed positions

        // Calculate the result and take modulo after multiplication
        return (power(5, evenCount, MOD) * power(4, oddCount, MOD)) % MOD;
    }
};
