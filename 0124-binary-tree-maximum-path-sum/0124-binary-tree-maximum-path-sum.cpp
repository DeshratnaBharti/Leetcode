
class Solution {
public:
    int maxPathSum(TreeNode* root) {
         int maxValue = INT_MIN; 
        function<int(TreeNode*)> depthFirstSearch = [&](TreeNode* node) {
            if (!node) {
                return 0; 
            }
           
            int leftMax = std::max(0, depthFirstSearch(node->left));
            int rightMax = std::max(0, depthFirstSearch(node->right));

            
            maxValue = std::max(maxValue, leftMax + rightMax + node->val);

          
            return node->val + std::max(leftMax, rightMax);
        };

       
        depthFirstSearch(root);

        return maxValue;
    }
};