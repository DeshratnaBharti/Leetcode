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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head or !head->next) return NULL;
         ListNode* fast =head;
          ListNode* slow = head;
          while(fast != NULL and fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;//iske baad slow mid par pahuch jayega

          }
          ListNode* curr = head;
          ListNode* prev= NULL;
          while(curr != slow){
            prev = curr;
            curr = curr->next;
          }
          prev->next = curr->next;
         return head;
    }
};