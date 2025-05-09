/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDiameter;
    int diameterOfBinaryTree(TreeNode* root) {
         maxDiameter = 0;
        depthFirstSearch(root);
        return maxDiameter;
    }

    // Helper function for DFS traversal of the tree.
    // Calculates the depth of the tree and updates the maximum diameter.
    int depthFirstSearch(TreeNode* node) {
        if (node == nullptr) return 0;  // Base case: return zero for null nodes.

        // Recursive DFS on the left child.
        int leftDepth = depthFirstSearch(node->left);
        // Recursive DFS on the right child.
        int rightDepth = depthFirstSearch(node->right);

        // Update the maximum diameter if the current node's diameter is greater.
        maxDiameter = max(maxDiameter, leftDepth + rightDepth);

        // Return the maximum depth from this node down to the leaf.
        return 1 + max(leftDepth, rightDepth);
    }
};