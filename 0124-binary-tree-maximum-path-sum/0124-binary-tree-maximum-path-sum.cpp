
class Solution {
public:
    int maxPathSum(TreeNode* root) {
         int maxValue = INT_MIN; // Initialize the maximum path sum as the smallest possible integer.

        // Depth-first search function to explore nodes and calculate max path sum.
        std::function<int(TreeNode*)> depthFirstSearch = [&](TreeNode* node) {
            if (!node) {
                return 0; // Base case: If the node is null, return 0 as it adds nothing to the path sum.
            }
            // Recursively calculate the max path sum for the left and right children, ignoring negative sums.
            int leftMax = std::max(0, depthFirstSearch(node->left));
            int rightMax = std::max(0, depthFirstSearch(node->right));

            // Update the global max path sum by considering the current node value and its maximum left and right path sums.
            maxValue = std::max(maxValue, leftMax + rightMax + node->val);

            // Return the maximum path sum of either the left or right subtree plus the current node value.
            return node->val + std::max(leftMax, rightMax);
        };

        // Start DFS from root.
        depthFirstSearch(root);

        return maxValue;
    }
};