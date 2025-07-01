class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        int n = s.length();
	int count = 0;

	// Check for all subarray of size K
	for (int i = 0; i < n - k + 1; i++) {
		vector<int> cnt(26, 0);

		for (int j=i; j<i+k; j++)
			cnt[s[j] - 'a']++;
			
		int distinctCnt = 0;

		// Count number of distinct characters
		for (int i=0; i<26; i++) {
		    if (cnt[i] > 0) {
		        distinctCnt++;
		    }
		}
		
		if (distinctCnt == k-1) count++;
	}

	return count;

    }
};