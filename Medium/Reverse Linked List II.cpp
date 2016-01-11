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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return NULL;
        if(m == n) return head;
        ListNode* dummy = new ListNode(0), *mp = dummy, *np = dummy, *start, *end = NULL;
        dummy->next = head;
        for(int i = 0; i < m - 1; i++) {
            mp = mp->next;
        }
        start = mp;
        mp = mp->next;
        for(int i = 0; i < n; i++) {
            np = np->next;
        }
        if(np) {
            end = np->next;
            np->next = NULL;
        }
        start->next = reverseList(mp);
        mp->next = end;
        start = dummy->next;
        delete dummy;
        return start;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        ListNode* dummy = new ListNode(0), *temp = head->next;
        dummy->next = head;
        while(temp) {
            head->next = temp->next;
            temp->next = dummy->next;
            dummy->next = temp;
            temp = head->next;
        }
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};