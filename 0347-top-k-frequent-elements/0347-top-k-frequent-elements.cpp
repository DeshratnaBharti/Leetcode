class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
            // Step 1: Count the frequency of each element
    unordered_map<int, int> freqMap;
    for (int num : nums) {
        freqMap[num]++;
    }

    // Step 2: Store the elements and their frequencies in a list of pairs
    vector<pair<int, int>> freqList;
    for (const auto& entry : freqMap) {
        freqList.push_back(entry);
    }

    // Step 3: Sort the list based on frequency in descending order
    sort(freqList.begin(), freqList.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    });

    // Step 4: Select the top K elements
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(freqList[i].first);
    }

    return result;
    }
};