
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0; 

        queue<pair<TreeNode*, unsigned long>> queue; 
        queue.push({root, 1}); 
        int maxWidth = 0; 

        while (!queue.empty()) {
            int levelSize = queue.size(); 
            unsigned long leftMost = queue.front().second;
            unsigned long rightMost = queue.back().second; 
            maxWidth = max(maxWidth, static_cast<int>(rightMost - leftMost) + 1); 
            for (int i = 0; i < levelSize; ++i) {
                auto nodePair = queue.front();
                queue.pop();
                TreeNode* currentNode = nodePair.first;
                unsigned long position = nodePair.second;

                position -= leftMost;

               
                if (currentNode->left) {
                    queue.push({currentNode->left, 2 * position}); 
                }
                if (currentNode->right) {
                    queue.push({currentNode->right, 2 * position + 1}); 
                }
            }
        }
        return maxWidth;
        
    }
};