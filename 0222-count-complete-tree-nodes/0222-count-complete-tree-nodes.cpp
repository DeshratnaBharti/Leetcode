class Solution {
public:
    int countNodes(TreeNode* root) {
       if(!root) return 0;
       int leftLevel=1;
       TreeNode* l= root->left;
       while(l){
        l=l->left;
        leftLevel += 1;
       } 
       int rightLevel=1;
       TreeNode* r= root->right;
       while(r){
        r=r->left;
        leftLevel += 1;
       } 
       if(leftLevel == rightLevel) return pow(2,leftLevel)-1;
       return 1+countNodes(root->left) + countNodes(root->right);


    }
};