class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        unordered_set<int> st;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
               
                 if (st.empty() && fruits[i] <= baskets[j]) {
                    st.insert(j);
                    break;
                }
                else if (!st.empty() && st.find(j) == st.end() && fruits[i] <= baskets[j]) {
                    st.insert(j);
                    break;
                }
                else {
                    continue;
                }
            }
        }
        return n - st.size();
    }
};
