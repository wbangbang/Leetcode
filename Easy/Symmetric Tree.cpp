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
    bool isSymmetric(TreeNode* root) {//iterative
        if(root == NULL) return true;
        stack<TreeNode*> left, right;
        TreeNode* l = root, *r = root;
        while(1) {
            if(l == NULL && r == NULL) {
                if(left.empty() && right.empty()) return true;
                else if(left.empty() || right.empty()) return false;
                else {
                    l = left.top()->right;
                    r = right.top()->left;
                    left.pop();
                    right.pop();
                    continue;
                }
            }
            else if(l == NULL || r == NULL) return false;
            else {
                if(l->val != r->val) return false;
                left.push(l);
                right.push(r);
                l = l->left;
                r = r->right;
            }
        }
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {//recursive
        if(!root) return true;
        return isSym(root->left, root->right);
    }
    
    bool isSym(TreeNode* left, TreeNode* right) {
        if(!left && !right) return true;
        if(!left || !right) return false;
        if(left->val != right->val) return false;
        return isSym(left->left, right->right) && isSym(left->right, right->left);
    }
};