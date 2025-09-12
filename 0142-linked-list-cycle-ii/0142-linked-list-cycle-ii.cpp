/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return NULL;
        ListNode* slow = head,*fast = head,*t = head;
        bool flag = false;

        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
             if(fast==slow){
                flag = true;
                break;
                 
             }
        }
        int i=0;
        
        if(flag == false) {
            return NULL;
        }
        else{
            
            while(slow!=t){
                slow= slow->next;
                t=t->next;
                i++;
            }
            return t;
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
       return hasCycle(head);

        
    }
};