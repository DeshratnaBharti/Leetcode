class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int, int> freq;
       for (int num : nums) freq[num]++;
         auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
              return a.second > b.second; 
         };
         priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
         for (auto& [num, count] : freq) {
            pq.push({num, count});
            if (pq.size() > k) pq.pop(); 
        }
         vector<int> result;
            while (!pq.empty()) {
                result.push_back(pq.top().first);
                pq.pop();
            }

    return result;
    }
};