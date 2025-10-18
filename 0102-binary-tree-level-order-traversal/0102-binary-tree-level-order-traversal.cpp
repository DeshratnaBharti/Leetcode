
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL) return{};
        vector<vector<int>>res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int>ans;
            while(n--){
                TreeNode* p = q.front();
                q.pop();
                ans.push_back(p->val);
                if(p->left != NULL) q.push(p->left);
                if(p->right != NULL) q.push(p->right);

            }
            res.push_back(ans);
        }
        return res;
    }
};