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
    TreeNode* invertTree(TreeNode* root) {//recursive
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {//iterative
        if(!root) return NULL;
        if(!root->left && !root->right) return root;
        queue<TreeNode*> myQ;
        myQ.push(root);
        while(!myQ.empty()) {
            TreeNode* temp = myQ.front();
            myQ.pop();
            if(temp->left) myQ.push(temp->left);
            if(temp->right) myQ.push(temp->right);
            TreeNode* node = temp->left;
            temp->left = temp->right;
            temp->right = node;
        }
        return root;
    }
};