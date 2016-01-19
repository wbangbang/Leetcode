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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* dummyO = new ListNode(0), *dummyE = new ListNode(0), *odd = head, *even = head->next, *temp = head->next->next;
        int flag = 1;
        dummyO->next = head;
        dummyE->next = head->next;
        while(temp) {
            if(flag == 1) {
                odd->next = temp;
                odd = odd->next;
            }
            else {
                even->next = temp;
                even = even->next;
            }
            flag = -flag;
            temp = temp->next;
        }
        odd->next = dummyE->next;
        even->next = nullptr;
        temp = dummyO->next;
        delete dummyO;
        delete dummyE;
        return temp;
    }
};