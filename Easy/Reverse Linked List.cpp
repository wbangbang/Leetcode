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

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {//recursive
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* dummy = new ListNode(0), *temp;
        temp = head->next;
        dummy->next = reverseList(head->next);
        temp->next = head;
        head->next = NULL;
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};