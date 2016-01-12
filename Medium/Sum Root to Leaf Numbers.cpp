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
    int sumNumbers(TreeNode* root) {
        return sumNums(root, 0);
    }
    
    int sumNums(TreeNode* root, int sum) {
        if(!root) return 0;
        if(!root->left && !root->right) {
            return sum * 10 + root->val;
        }
        return sumNums(root->left, sum * 10 + root->val) + sumNums(root->right, sum * 10 + root->val);
    }
};