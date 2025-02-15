
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
          vector<int> result; // Holds the postorder traversal result
        // Loop until there are no nodes to process
        while (root) {
            // If the right subtree does not exist, process the current node and move to the left subtree
            if (!root->right) {
                result.push_back(root->val);
                root = root->left;
            } else {
                // Find the rightmost node of the left subtree or the left child of the previous processed node
                TreeNode* next = root->right;
                while (next->left && next->left != root) {
                    next = next->left;
                }
              
                // Establish a temporary link so we can return to the current node after traversing its right subtree
                if (!next->left) {
                    result.push_back(root->val); // Process the current node
                    next->left = root; // Establish the temporary link
                    root = root->right; // Move to the right subtree
                } else {
                    next->left = nullptr; // Remove the temporary link
                    root = root->left; // Move to the left subtree since the right subtree has been processed
                }
            }
        }
        // Reverse the results because the nodes were visited in reverse postorder
        reverse(result.begin(), result.end());
        return result;
    }
};