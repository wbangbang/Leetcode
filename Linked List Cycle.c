/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if((head == NULL)||(head->next == NULL)) return 0;
    struct ListNode *q=head->next;
    struct ListNode *l=head;
    while(q) {
        if(q == l) return 1;
        if(!q->next) return 0;
        q = q->next->next;
        l = l->next;
    }
    return 0;    
}