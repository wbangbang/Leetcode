/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//iterative
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int max = maxV(p, q), min = minV(p, q);
        if(root == NULL) return NULL;
        TreeNode* temp = root;
        while(temp != NULL) {
            if(temp->val == max || temp->val == min) return temp;
            if(temp->val > max) {
                temp = temp->left;
            }
            else if(temp->val < min) {
                temp = temp->right;
            }
            else return temp;
        }
    }
    
    int maxV(TreeNode* p, TreeNode* q) {
        if(p->val > q->val) return p->val;
        else return q->val;
    }
    
    int minV(TreeNode* p, TreeNode* q) {
        if(p->val < q->val) return p->val;
        else return q->val;
    }
};

class Solution {//recursive
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return root;
        if(root->val <= max(p->val, q->val) && root->val >= min(p->val, q->val)) return root;
        else if(root->val < min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        }
        else {
            return lowestCommonAncestor(root->left, p, q);
        }
    }
};