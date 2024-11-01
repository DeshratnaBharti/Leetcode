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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL) return NULL;
        bool flag = false;
        ListNode *slow = head , *fast = head;
        while(fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                flag = true;
                break;
            }
        }
        if(flag == false) return NULL;
        else{
            ListNode *post = head;
            while(post != slow){
                post = post->next;
                slow = slow->next;
            }
return post;
        }
         // return post;
    }
};