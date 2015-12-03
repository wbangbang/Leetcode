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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int h1 = height(root->left);
        int h2 = height(root->right);
        if(h1 < 0 || h2 < 0) return false;              //non-balanced subtree exists then return false 
        if((h1 > h2 ? h1 - h2 : h2 - h1) <= 1) return true;
        else return false;
    }
    
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        if(h1 < 0 || h2 < 0) return -1;         //if any subtrees are not balanced then return -1
        if((h1 > h2 ? h1 - h2 : h2 - h1) <= 1) {//if balanced return its height
            return 1 + (h1 > h2 ? h1 : h2);
        }
        else return -1;                         //if not balanced then return -1
    }
};