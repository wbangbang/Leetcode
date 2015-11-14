/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//Brute force
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* p, *q, *headNew;
    if(head==NULL) return 0;
    q=head;
    while(q->next!=NULL) {
        q=q->next;
    }
    p=q;
    headNew=p;
    while(p!=head) {
        q=head;
        while(q->next!=p) {
            q=q->next;
        }
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return headNew;
}