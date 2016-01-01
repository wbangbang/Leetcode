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
    int closestValue(TreeNode* root, double target) {//root is not NULL
        if(root->val == target) return root->val;
        if(!root->left && !root->right) return root->val;
        if(target > root->val) {
            if(!root->right) return root->val;//avoid NULL
            int temp = closestValue(root->right, target);
            if(abs(temp - target) < abs(root->val - target)) {//determine which is closest
                return temp;
            }
            else return root->val;
        }
        else {
            if(!root->left) return root->val;
            int temp = closestValue(root->left, target);
            if(abs(temp - target) < abs(root->val - target)) {
                return temp;
            }
            else return root->val;
        }
    }
};