
class Solution {
public:
    TreeNode* f(vector<int>&nums,int s,int l){
        if(s>l) return nullptr;
        int mid = (s+l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = f(nums,s,mid-1);
        root->right = f(nums,mid+1,l);

        return root;

    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return f(nums,0,nums.size()-1);
    }
};