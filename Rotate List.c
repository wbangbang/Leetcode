/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    struct ListNode* p, *q, *headNew = NULL;
    int i,n = 1;
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    headNew = (struct ListNode*)malloc(sizeof(struct ListNode));
    headNew->next = head;
    p = head->next;
    while(p) {
        p = p->next;
        ++n;
    }
    if(k > n)
        k = k % n;
    if((k < n)&&(k != 0)) {
        p = head;
        for(i = 0; i < (n - k - 1); i++) {
            p = p->next;
        }
        q = head;
        for(i = 0; i < (n - 1); i++) {
            q = q->next;
        }
        headNew->next = p->next;
        p->next = NULL;
        q->next = head;
        return headNew->next;
    }
    if(k == n || k == 0) return head;
    
}