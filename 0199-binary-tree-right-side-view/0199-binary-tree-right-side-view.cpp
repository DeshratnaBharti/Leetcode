
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int n = q.size();
             TreeNode* node =NULL;
            while(n--){
                node = q.front();
                q.pop();
                if(node->left != NULL)q.push(node->left);
                if(node->right != NULL)q.push(node->right);
            }
            ans.push_back(node->val);
        }
        return ans;

    }
};