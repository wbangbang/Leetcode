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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p) return nullptr;
        if(p->right) {
            p = p->right;
            while(p->left) {
                p = p->left;
            }
            return p;
        }
        if(root == p) return nullptr;
        if(root->val > p->val) {
            if(root->left == p) return root;
            TreeNode* left = inorderSuccessor(root->left, p);
            if(left) return left;
            return root;
        }
        else {
            if(root->right == p) return nullptr;
            return inorderSuccessor(root->right, p);
        }
    }
};