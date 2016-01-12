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
    ListNode* partition(ListNode* head, int x) {
        ListNode* tempL = NULL, *tempS = NULL, *curr = head, *start = NULL, *newHead = head;
        while(curr) {
            if(curr->val < x) {
                if(!tempS) {
                    tempS = curr;
                    newHead = curr;
                }
                else {
                    tempS->next = curr;
                    tempS = curr;
                }
            }
            else {
                if(!tempL) {
                    tempL = curr;
                    start = curr;
                }
                else {
                    tempL->next = curr;
                    tempL = curr;
                }
            }
            curr = curr->next;
            if(!curr) {
                if(tempS) tempS->next = start;
                if(tempL) tempL->next = NULL;
            }
        }
        return newHead;
    }
};