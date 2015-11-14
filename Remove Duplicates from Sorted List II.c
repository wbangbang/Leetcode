/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//if want to delete a pointer p, you cannot only do like this: p = NULL; you must set the next of the pointer before p NULL.  
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* p, *headNew;
    int val, f = 0;
    if(head == NULL) return NULL;
    if(head->next == NULL) return head;
    p = head;
    headNew = (struct ListNode*)malloc(sizeof(struct ListNode));
    headNew->next = head;
    val = p->val;
    while(val == p->next->val) {
        f = 1;                  //determine if the head has the same value as the nodes behind it.
        p->next = p->next->next;
        if(!p->next) {          //if every nodes except the head has the same value as the head, the list must be NULL.
            return NULL;
        }
    }
    if(f) {                     //if so, the head needs to be deleted and there will be a new head.
        headNew->next = deleteDuplicates(p->next); 
    }
    else {                      //otherwise, we can keep the head.
        head->next = deleteDuplicates(p->next);
    }
    return headNew->next;
}