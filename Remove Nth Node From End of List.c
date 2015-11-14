/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* p = head, *q = head;
    int t = 1;
    if(head == NULL) return NULL;
    if(head->next == NULL) return NULL;
    while(p->next) {
        p = p->next;
        ++t;
    }
    if(n == t) return head->next;
    else {
        for(int i = 1; i <= (t-n); i++) {
            q = q->next;            
        }
        if(q->next) {
            q->val = q->next->val;
            q->next = q->next->next;
        }
        else {
            p = head;                                           //Notice: q = NULL is just to make the q pointer null.
            while(p->next != q){
                p = p->next;
            }
            p->next = NULL;
        }
        return head;
    }
    
    
}