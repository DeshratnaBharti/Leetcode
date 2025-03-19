class Solution {
public:
    vector<int>in;
    void inorder(TreeNode* root){
        if(root==NULL) return ;
        inorder(root->left);
        in.push_back(root->val);
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l=0,r=in.size()-1;
        while(l<r){
            if(in[l]+in[r]==k) return true;
            else if(in[l]+in[r]<k) l++;
            else r--;
        }
        return false;
    }
};