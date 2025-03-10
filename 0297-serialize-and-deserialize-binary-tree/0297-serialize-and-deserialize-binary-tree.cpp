class Codec {
public:
   void dfs(TreeNode* curr,string& s){
       if(!curr){
          s.push_back('*');
          return;
       }
       s.append(to_string(curr->val)+",");
       dfs(curr->left,s);
       dfs(curr->right,s);
   }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        dfs(root,s);
        return s;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* decode(string& data){
        if(data.size()==0) return NULL;
        if(data[0]=='*'){
            data = data.substr(1);
            return NULL;
        }
        int i=0;
        string treeN="";
        while(data[i] !=',') treeN += data[i++];
        TreeNode *curr = new TreeNode(stoi(treeN));
        data = data.substr(i+1);//trim the string
        curr->left=decode(data);
        curr->right=decode(data);
        return curr;
    }
    TreeNode* deserialize(string data) {
        if(data.size()<=1) return NULL;
        return decode(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));