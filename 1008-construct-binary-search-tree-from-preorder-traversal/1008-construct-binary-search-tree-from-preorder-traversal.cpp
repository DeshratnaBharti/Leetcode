class Solution {
public:
    TreeNode* buildBST(TreeNode* &root,int ele){
        if(root==NULL) return root = new TreeNode(ele);
        if(root->val > ele) root->left = buildBST(root->left,ele);
        else root->right = buildBST(root->right,ele);
        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode *root = NULL;
       for(auto x : preorder){
        buildBST(root,x);
       }
       return root;
    }
};