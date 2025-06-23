class Solution {
public:
    bool isPalindrome(string s) {
        return s == string(s.rbegin(), s.rend());
    }

    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += (num % k) + '0';
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    void generatePalindromes(vector<long long>& palindromes, int length) {
        int start = pow(10, (length - 1) / 2);
        int end = pow(10, (length + 1) / 2);
        for (int i = start; i < end; ++i) {
            string half = to_string(i);
            string full = half + string(half.rbegin() + (length % 2), half.rend());
            palindromes.push_back(stoll(full));
        }
    }

    long long kMirror(int k, int n) {
        long long sum = 0;
        int length = 1;
        while (n > 0) {
            vector<long long> palindromes;
            generatePalindromes(palindromes, length++);
            for (long long num : palindromes) {
                if (isPalindrome(toBaseK(num, k))) {
                    sum += num;
                    if (--n == 0) break;
                }
            }
        }
        return sum;
    }
};
