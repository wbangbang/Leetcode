/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {//destroy the list
        if(!head) return NULL;
        if(!head->next) {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        ListNode* fast = head, *slow = head, *midBefore = head;
        int i = 0;
        while(fast && fast->next) {
            if(i >= 1) midBefore = midBefore->next;
            fast = fast->next->next;
            slow = slow->next;
            i++;
        }
        TreeNode* root = new TreeNode(slow->val);
        midBefore->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        ListNode* curr = head;
        int len = 0;
        while(curr) {
            len++;
            curr = curr->next;
        }
        return helper(head, 1, len);
    }
    
    TreeNode* helper(ListNode*& head, int start, int end) {
        if(start > end) return NULL;
        int mid = (start + end) >> 1;
        TreeNode* left = helper(head, start, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* right = helper(head, mid + 1, end);
        root->left = left;
        root->right = right;
        return root;
    }
};