class Solution {
  public:
    bool sameFreq(string& s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }

        unordered_map<int, int> freqCount;
        for (auto& pair : freq) {
            freqCount[pair.second]++;
        }

        if (freqCount.size() == 1) return true; // All frequencies are equal

        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int f1 = it->first, c1 = it->second;
            ++it;
            int f2 = it->first, c2 = it->second;

            // Check if one frequency is 1 and occurs only once
            if ((f1 == 1 && c1 == 1) || (f2 == 1 && c2 == 1)) {
                return true;
            }

            // Check if one frequency is greater by 1 and occurs only once
            if ((abs(f1 - f2) == 1) && ((f1 > f2 && c1 == 1) || (f2 > f1 && c2 == 1))) {
                return true;
            }
        }

        return false;
    }
};
