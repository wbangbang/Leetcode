/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* temp;
public:
    bool isPalindrome(ListNode* head) {
        temp = head;
        return isPal(head);
    }
    
    bool isPal(ListNode* h) {
        if(!h) return true;
        bool res = isPal(h->next) && (temp->val == h->val);
        temp = temp->next;
        return res;
    }
};

class Solution {//reverse half
public:
    bool isPalindrome(ListNode* head) {
        if(!head) return true;
        ListNode* fast = head, *mid = head, *start;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            mid = mid->next;
        }
        start = reverse(mid->next);
        while(start) {
            if(head->val != start->val) return false;
            head = head->next;
            start = start->next;
        }
        return true;
    }
    ListNode* reverse(ListNode* h) {
        if(!h || !h->next) return h;
        ListNode* hr, *temp = h->next;
        hr = reverse(h->next);
        temp->next = h;
        h->next = NULL;
        return hr;
    }
};