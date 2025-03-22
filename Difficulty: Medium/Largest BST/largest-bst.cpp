//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
        // Helper function to compute the largest BST
      int maxSize = 0;

    int largestBST(Node* root, int& minVal, int& maxVal, bool& isBST) {
        if (!root) {
            // An empty tree is a valid BST with min = INT_MAX and max = INT_MIN
            isBST = true;
            minVal = INT_MAX;
            maxVal = INT_MIN;
            return 0;
        }

        int leftMin, leftMax, rightMin, rightMax;
        bool leftIsBST, rightIsBST;

        // Recursively calculate for left and right subtrees
        int leftSize = largestBST(root->left, leftMin, leftMax, leftIsBST);
        int rightSize = largestBST(root->right, rightMin, rightMax, rightIsBST);

        // Current subtree min and max
        minVal = min(root->data, leftMin);
        maxVal = max(root->data, rightMax);

        // Check if the current subtree is a BST
        if (leftIsBST && rightIsBST && leftMax < root->data && root->data < rightMin) {
            int currSize = leftSize + rightSize + 1;
            maxSize = max(maxSize, currSize); // Update the largest BST size
            isBST = true;
            return currSize;
        }

        // If not a BST, propagate the largest valid BST size from children
        isBST = false;
        return 0;
    }

    int largestBst(Node *root)
    {
       int minVal, maxVal;
        bool isBST;
        largestBST(root, minVal, maxVal, isBST);
        return maxSize;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends