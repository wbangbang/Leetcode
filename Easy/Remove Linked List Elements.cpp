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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0), *temp = head, *bf = dummy;
        dummy->next = head;
        while(temp) {
            if(temp->val == val) {
                bf->next = temp->next;
                temp = bf->next;
            }
            else {
                temp = temp->next;
                bf = bf->next;
            }
        }
        bf = dummy->next;
        delete dummy;
        return bf;
    }
};