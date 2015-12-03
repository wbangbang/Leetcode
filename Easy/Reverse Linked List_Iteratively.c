/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//Iteratively
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* p = NULL, *q = NULL, *headNew = NULL;
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    headNew = (struct ListNode*)malloc(sizeof(struct ListNode));
    headNew->next = head;
    p = head->next;
    while(p) {
        q = p->next;
        p->next = headNew->next;
        headNew->next = p;
        p = q;
    }
    head->next = NULL;
    return headNew->next;
}