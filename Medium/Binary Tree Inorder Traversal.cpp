/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//recursive
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& res) {
        if(!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
        return;
    }
};

class Solution {//iterative
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> myStack;
        TreeNode* temp = root;
        myStack.push(temp);
        while(temp->left) {
            temp = temp->left;
            myStack.push(temp);
        }
        while(!myStack.empty()) {
            temp = myStack.top();
            myStack.pop();
            res.push_back(temp->val);
            if(temp->right) {
                temp = temp->right;
                myStack.push(temp);
                while(temp->left) {
                    temp = temp->left;
                    myStack.push(temp);
                }
            }
        }
        return res;
    }
};