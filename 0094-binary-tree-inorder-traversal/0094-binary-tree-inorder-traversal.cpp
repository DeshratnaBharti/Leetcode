
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        TreeNode* curr = root;
        vector<int>ans;
        while(curr){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else{
                TreeNode* lc = curr->left;
                while(lc->right != NULL){
                    lc = lc->right;
                }
                lc->right = curr;
                TreeNode* Temp = curr;
                curr = curr->left;
                Temp->left = NULL;
            }
        }
        return ans;
    }
};