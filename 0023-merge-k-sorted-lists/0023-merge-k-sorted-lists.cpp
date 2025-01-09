/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
ListNode* merge(ListNode* list1, ListNode* list2) {

       ListNode* tempA = list1;
       ListNode* tempB = list2;
       ListNode* c =new  ListNode(100);
        ListNode* temp = c;
       while(tempA != NULL and tempB != NULL){
          if(tempA->val>= tempB->val){
            temp->next=tempB;
            tempB=tempB->next;
            temp=temp->next;
          }else{
            temp->next=tempA;
            tempA=tempA->next;
            temp=temp->next;
          }
       }
       if(tempA != NULL) temp->next=tempA;
       else temp->next= tempB;
       return c->next;


    }
    ListNode* mergeKLists(vector<ListNode*>& arr) {
        if(arr.size()==0) return NULL;
        while(arr.size()>1){
            ListNode*  a= arr[arr.size()-1];
            arr.pop_back();
            ListNode*  b= arr[arr.size()-1];
            arr.pop_back();
            ListNode* c = merge(a,b);
            arr.push_back(c);
        }
      return arr[0];        
    }
};