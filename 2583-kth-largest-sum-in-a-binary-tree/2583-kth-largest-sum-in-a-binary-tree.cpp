/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>que;
        que.push(root);
        vector<long long>s;
        while(!que.empty()){
            int N = que.size();
            long long sum = 0;
            while(N--){
                auto node = que.front();
                que.pop();
                sum += node->val;
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);


            }
            s.push_back(sum);
        }
        if(k > s.size()) return -1;
        sort(s.begin(),s.end());
        return s[s.size()-k];
        
    }
};