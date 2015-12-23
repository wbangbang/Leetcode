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
    ListNode* sortList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* slow = head, *fast = head, *temp = head;
        int c = 0;
        while(fast && fast->next) {
            if(c) {
                temp = temp->next;
            }
            fast = fast->next->next;
            slow = slow->next;
            c++;
        }
        temp->next = NULL;
        return merge(sortList(head), sortList(slow));
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }
        else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};