class Solution {
public:
bool exists(TreeNode* root,TreeNode* target){
    if(root==NULL) return false;
    if(root==target) return true;
    return exists(root->left,target) || exists(root->right,target);
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==p or root == q) return root;
            //case 1: p root ke left me exist karta hai aur q root ke right me
            else if(exists(root->left,p)==true and exists(root->right,q)==true) return root;
            //case 2: p root ke rigt me exist karta hai aur q root ke left me 
            else if(exists(root->right,p)==true and exists(root->left,q)==true) return root;
            //case 3: p root ke left me exist karta hai aur q bhi root ke left me 
            else if(exists(root->left,p)==true and exists(root->left,q)==true) return lowestCommonAncestor(root->left,p,q);
            //case 4: p root ke right ke right me exist karta hai aur q bhi root ke right me 
            else return lowestCommonAncestor(root->right,p,q);
    }
};