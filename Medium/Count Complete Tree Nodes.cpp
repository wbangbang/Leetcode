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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int hl = findHeight(root->left);
        int hr = findHeight(root->right);
        if(hl == hr) {
            return (1 << hl) + countNodes(root->right);
        }
        else {
            return (1 << hr) + countNodes(root->left);
        }
        
    }
    
    int findHeight(TreeNode* root) {
        if(!root) return 0;
        return 1 + findHeight(root->left);//the tree is completely filled: if the left child is null, the right child is null.
    }
};