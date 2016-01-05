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
        if(!head || !head->next) return NULL;
        ListNode* fast = head->next->next, *slow = head->next;
        while(fast && fast != slow) {
            slow = slow->next;
            fast = fast->next;
            fast = fast == NULL? NULL: fast->next;
        }
        if(!fast) return NULL;
        for(fast = head; fast != slow; fast = fast->next) {
            slow = slow->next;
        }
        return fast;
    }
};