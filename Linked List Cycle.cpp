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
    bool hasCycle(ListNode *head) {
        set<ListNode*> s;               //Notice: the type of set.
        struct ListNode *p=head;
        if(head == NULL) return 0;
        while(1) {
            if(s.count(p) != 0) return 1;//find() will return an iterator so it cannot compare with 0
            else {
                s.insert(p);
                p = p->next;
            }
            if(!p) return 0;
        }
    }
};