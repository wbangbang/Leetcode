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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0);
        ListNode* fast = dummy, *slow = dummy, *temp;
        dummy->next = head;
        int i = 0;
        while(fast) {
            if(i > n) slow = slow->next;
            fast = fast->next;
            i++;
        }
        slow->next = slow->next->next;
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};