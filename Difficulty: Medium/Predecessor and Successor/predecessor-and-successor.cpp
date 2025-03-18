//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends


class Solution
{
    public:
    ////int suc ;
    //int pre;
   Node* findPredecessor(Node* root, Node*& pre, int key) {
    pre = root->left;
    while (pre && pre->right) { // Check if 'pre' is not null
        pre = pre->right;
    }
    return pre;
}

Node* findSuccessor(Node* root, Node*& suc, int key) {
    suc = root->right;
    while (suc && suc->left) { // Check if 'suc' is not null
        suc = suc->left;
    }
    return suc;
}

    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
         if (!root) return;

    // Check if the current node is the key
    if (root->key == key) {
        // Call the helper functions
      if (root->left) pre = findPredecessor(root, pre, key);

        if (root->right) suc = findSuccessor(root, suc,key);
        return;
    }

    // If the key is smaller than root's key, traverse left subtree
    if (key < root->key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    // If the key is larger than root's key, traverse right subtree
    else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    }
};


//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   
cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends