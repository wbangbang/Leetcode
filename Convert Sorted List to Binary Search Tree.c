/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedListToBST(struct ListNode* head) {
    int i,n = 0;
    struct ListNode* p = head, *q = NULL;
    struct TreeNode* root;
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if(head == NULL) return NULL;
    if(head->next == NULL){
        root->val = head->val;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    while(p) {
        ++n;
        p = p->next;
                    //if"++n" located here, the n will be wrong number.
    }
    if(n % 2 == 0) {
        p = head;
        for(i = 0; i < (n/2 -1); i++) {
            p = p->next;
        }
        q = p->next;
        p->next = NULL;
        root->val = q->val;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(q->next);
        return root;
    }
    else {
        p = head;
        for(i = 0; i < ((n+1)/2 -2); i++) {     //here (n+1)/2-2 instead of (n+1)/2-1
            p = p->next;
        }
        q = p->next;
        p->next = NULL;
        root->val = q->val;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(q->next);
        return root;
    }

}