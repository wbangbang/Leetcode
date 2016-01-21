/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//iterative
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* dummy = new ListNode(0), *curr = head->next, *temp;
        dummy->next = head;
        while(curr) {
            temp = curr->next;
            curr->next = dummy->next;
            dummy->next = curr;
            curr = temp;
        }
        head->next = NULL;
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};

class Solution {//recursive
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* headr, *temp = head->next;
        headr = reverseList(head->next);
        temp->next = head;
        head->next = NULL;
        return headr;
    }
};