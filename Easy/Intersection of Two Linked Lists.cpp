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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        ListNode* hA = headA, *hB = headB;
        int len1 = 0, len2 = 0;
        while(hA) {
            hA = hA->next;
            len1++;
        }
        while(hB) {
            hB = hB->next;
            len2++;
        }
        if(len1 == len2) {
            while(headA && headB) {
                if(headA == headB) return headA;
                headA = headA->next;
                headB = headB->next;
            }
        }
        else if(len1 > len2) {
            int i = 0;
            while(headA && headB) {
                if(headA == headB) return headA;
                if(i >= len1 - len2) headB = headB->next;
                headA = headA->next;
                i++;
            }
        }
        else {
            int i = 0;
            while(headA && headB) {
                if(headA == headB) return headA;
                if(i >= len2 - len1) headA = headA->next;
                headB = headB->next;
                i++;
            }
        }
        return false;
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
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //input check
        if(!headA || !headB) return NULL;
        ListNode* hA = headA, *hB = headB;
        while(hA != hB) {
            hA = hA == NULL? headB: hA->next;
            hB = hB == NULL? headA: hB->next;
        }
        return hA;
    }
};