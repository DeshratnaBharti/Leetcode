class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int>ans;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                ans.push_back(curr->val);
                curr= curr->right;
            }else{
                TreeNode* leftChild = curr->left;
                while(leftChild->right != NULL and leftChild->right != curr){
                    leftChild = leftChild->right;
                }
                if(leftChild->right == NULL){
                  leftChild->right = curr;
                   ans.push_back(curr->val);
                
                   curr= curr->left;
                }
                else{
                    leftChild->right = NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }
};