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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        int n = lists.size(), end = n - 1;
        while(end > 0) {
            int begin = 0;
            while(begin < end) {
                lists[begin] = mergeTwoLists(lists[begin], lists[end]);
                begin++;
                end--;
            }
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode* dummy = new ListNode(0), *temp = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                temp->next = l1;
                l1 = l1->next;
            }
            else {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }
        if(l1) {
            temp->next = l1;
        }
        else if(l2) {
            temp->next = l2;
        }
        else temp->next = NULL;
        temp = dummy->next;
        delete dummy;
        return temp;
    }
};