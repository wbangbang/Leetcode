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
    bool isValidBST(TreeNode* root) {
        TreeNode* temp = NULL;
        if(!root) return true;
        if(!root->left && !root->right) return true;
        if(root->right && root->right->val <= root->val) return false;
        if(root->left && root->left->val >= root->val) return false;
        if(!isValidBST(root->left) || !isValidBST(root->right)) return false;
        if(root->right) { /* to see if the min-val in the right subtree is larger than the root-val */
            temp = root->right;
            while(temp->left) {
                temp = temp->left;
                if(temp->val <= root->val) return false;
            }
        }
        if(root->left) { /* to see if the max-val in the left subtree is smaller than the root-val */
            temp = root->left;
            while(temp->right) { 
                temp = temp->right;
                if(temp->val >= root->val) return false;
            }
        }
        return true;
    }
};