
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
      ListNode* temp = new ListNode(0),*curr1=list1,*curr2=list2;
      ListNode* t= temp;
      while(curr1 and curr2){
        if(curr1->val<curr2->val){
            temp->next = curr1;
            temp = temp->next;
            curr1=curr1->next;
        }else{
            temp->next = curr2;
            temp=temp->next;
            curr2= curr2->next;
        }
      }
      while(curr1){
        temp->next=curr1;
        temp=temp->next;
        curr1=curr1->next;

      }
      while(curr2){
        temp->next=curr2;
        temp= temp->next;
        curr2=curr2->next;
      }
      return t->next;
        
    }
};