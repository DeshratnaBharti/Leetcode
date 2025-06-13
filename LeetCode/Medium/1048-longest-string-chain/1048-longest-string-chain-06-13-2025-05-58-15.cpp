class Solution {
public:
     int t[10001][10001];
int n;

bool isPred(string &prev, string &curr) {
    int M = prev.length();
    int N = curr.length();
    if (M >= N || N - M != 1) return false;
    int i = 0, j = 0;
    while (i < M && j < N) {
        if (prev[i] == curr[j]) i++;
        j++;
    }
    return i == M;
}

int lis(vector<string> &words, int prev_idx, int curr_idx) {
    if (curr_idx == n) return 0;

    if (prev_idx != -1 && t[prev_idx][curr_idx] != -1) {
        return t[prev_idx][curr_idx];
    }

    int taken = 0, nottaken = 0;

    if (prev_idx == -1 || isPred(words[prev_idx], words[curr_idx])) {
        taken = 1 + lis(words, curr_idx, curr_idx + 1);
    }
    nottaken = lis(words, prev_idx, curr_idx + 1);

    if (prev_idx != -1) {
        return t[prev_idx][curr_idx] = max(taken, nottaken);
    }
    return max(taken, nottaken);}

    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
    n = words.size();
    sort(words.begin(), words.end(), [](auto &s1, auto &s2) {
        return s1.length() < s2.length();
    });
    return lis(words, -1, 0);

    }
};