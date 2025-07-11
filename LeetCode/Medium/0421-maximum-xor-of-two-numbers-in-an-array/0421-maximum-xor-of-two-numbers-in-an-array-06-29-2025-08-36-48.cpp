class Solution {
public:
     struct trieNode{
        trieNode* left;
        trieNode* right;
     };
    void insert(trieNode* root,int &num){
        trieNode* pCrawl = root;
        for(int i=31;i>=0;i--){
            int i_th_bit=(num>>i)&1;
            if(i_th_bit==0){
                if(pCrawl->left==NULL){
                    pCrawl->left=new trieNode();
                }
                pCrawl = pCrawl->left;
            }else{
                if(pCrawl->right==NULL){
                    pCrawl->right=new trieNode();
                }
                pCrawl = pCrawl->right;
            }
        }
    }
    int findMaxXor(trieNode* root,int &num){
        int maxXor =0;
        trieNode* pCrawl = root;
        for(int i=31;i>=0;i--){
            int ith_bit = (num>>i)&1;
            if(ith_bit==1){
                if(pCrawl->left!=NULL){
                    maxXor +=pow(2,i);
                    pCrawl = pCrawl->left;
                }else{
                    pCrawl= pCrawl->right;
                }
            }else{
                if(pCrawl->right!=NULL){
                    maxXor +=pow(2,i);
                    pCrawl = pCrawl->right;
                }else{
                    pCrawl= pCrawl->left;
                }
            }
        }
        return maxXor;
    }
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        trieNode* root = new trieNode();
        for(int &num:nums){
            insert(root,num);
        }
        int maxResult=0;
        for(int i=0;i<n;i++){
            int temp = findMaxXor(root,nums[i]);
            maxResult = max(maxResult,temp);
        }
        return maxResult;
    }
};