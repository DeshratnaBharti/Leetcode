
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> result; // This vector will hold the preorder traversal result

        while (root != nullptr) { // Continue until there are no more nodes to visit
            if (root->left == nullptr) { 
                // If there is no left child, visit this node and move to the right child
                result.push_back(root->val);
                root = root->right;
            } else { 
                // If there is a left child, find the rightmost node of the
                // left subtree or a previously created link to the current node
                TreeNode* previous = root->left;
                while (previous->right != nullptr && previous->right != root) {
                    previous = previous->right;
                }

                if (previous->right == nullptr) {
                    // Establish a temporary link back to the current node
                    // so we can return after exploring left subtree
                    result.push_back(root->val); // Visit the current node
                    previous->right = root; // Make link to go back to root after left subtree is done
                    root = root->left; // Move to the left subtree
                } else {
                    // Left subtree has been visited, remove the link
                    previous->right = nullptr;
                    // Move to the right subtree
                    root = root->right;
                }
            }
        }
        return result;
    }
};