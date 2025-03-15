class Solution {
public:
    TreeNode* iop(TreeNode* root){
        TreeNode* pred = root->left;
        while(pred->right){
            pred=pred->right;
        }
        return pred;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val ==key){
            if(root->left ==NULL and root->right==NULL) return NULL;
            if(root->left==NULL or root->right==NULL){
                if(root->left != NULL) return root->left;
                else return root->right;
            }
            //case 3 : 2 child Nodes
            if(root->left !=NULL and root->right != NULL){
                TreeNode* pred = iop(root);
                root->val = pred->val;
                root->left=deleteNode(root->left,pred->val);

            } 
        }
        else if(root->val >key){
            root->left = deleteNode(root->left,key);

        }else{
            root->right = deleteNode(root->right,key);
        }
        return root;
    }
};