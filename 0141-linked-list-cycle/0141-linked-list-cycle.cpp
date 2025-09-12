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
    bool hasCycle(ListNode *head) {
        if(head==NULL or head->next==NULL) return false;
        ListNode* slow = head,*fast = head;
        bool flag = true;
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
             if(fast==slow){
                flag = false;
                break;
                 
             }
        }
        if(flag == false) return true;
        return false;
    }
};