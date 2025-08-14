class Solution {
public:
    int s(vector<int>& arr, int n) {
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
            c *= arr[i];
        }
        return c;
    }

    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        int m = 1;
        vector<int> zeroIndices;
        
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zeroIndices.push_back(i);
            } else {
                m *= arr[i];
            }
        }

        vector<int> ans(n, 0);

        if (zeroIndices.size() > 1) {
            // Agar 2 ya zyada zeros hain, ans already zero hai
            return ans;
        }

        if (zeroIndices.size() == 1) {
            int mul = s(arr, n);
            ans[zeroIndices[0]] = mul; // Sirf zero wale index pe product
        } else {
            for (int i = 0; i < n; i++) {
                ans[i] = m / arr[i];
            }
        }

        return ans;
    }
};
