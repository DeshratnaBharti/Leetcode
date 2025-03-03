
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0; // Guard clause for an empty tree

        std::queue<std::pair<TreeNode*, unsigned long>> queue; // Queue to perform level order traversal, holding nodes and their positions
        queue.push({root, 1}); // Initialize with the root node with position 1
        int maxWidth = 0; // Variable to store the maximum width found

        while (!queue.empty()) {
            int levelSize = queue.size(); // Number of nodes at the current level
            unsigned long leftMost = queue.front().second; // Position of the leftmost node at the current level, used as an offset
            unsigned long rightMost = queue.back().second; // Position of the rightmost node at the current level, used to calculate width
            maxWidth = std::max(maxWidth, static_cast<int>(rightMost - leftMost) + 1); // Update maxWidth if necessary

            // Iterate through the nodes of the current level
            for (int i = 0; i < levelSize; ++i) {
                auto nodePair = queue.front();
                queue.pop();
                TreeNode* currentNode = nodePair.first;
                unsigned long position = nodePair.second;

                // Subtract leftMost to avoid high values and overflow due to increasing node positions
                position -= leftMost;

                // Add children to the queue with their respective positions
                if (currentNode->left) {
                    queue.push({currentNode->left, 2 * position}); // Left child position
                }
                if (currentNode->right) {
                    queue.push({currentNode->right, 2 * position + 1}); // Right child position
                }
            }
        }
        return maxWidth;
        
    }
};