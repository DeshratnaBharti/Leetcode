
class Solution {
public:
    int levels(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(levels(root->left),levels(root->right));
    }
    void nthLevels(TreeNode* root,int curr,int level,vector<int>&v){
        if(root ==NULL) return;
       if(level%2 !=0) {
           if(curr==level){
            v.push_back(root->val);
            return;
        }
        nthLevels(root->left,curr+1,level,v);
        nthLevels(root->right,curr+1,level,v);
       }else{
          if(curr==level){
            v.push_back(root->val);
            return;
        }
        nthLevels(root->right,curr+1,level,v);
        nthLevels(root->left,curr+1,level,v);

       }
    }
    void lOrder(TreeNode* root,vector<vector<int>>&ans){
        int n= levels(root);
        for(int i=1;i<=n;i++){
            vector<int>v;
            nthLevels(root,1,i,v);
            ans.push_back(v);

        }
    }
    //
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
        lOrder(root,ans);
         return ans;  
    }
};