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
    void flatten(TreeNode* root) {
        TreeNode* temp;
        if(!root) return;
        if(!root->left && !root->right) return;
        flatten(root->left);
        flatten(root->right);
        if(root->left) {
            temp = root->right;
            root->right = root->left;
            root->left = NULL;
            while(root->right) {
                root = root->right;
            }
            root->right = temp;
        }
    }
};