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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL) return v;
        if(root->left != NULL) {
            vector<int> temp;
            temp = inorderTraversal(root->left);
            for(int i = 0; i < temp.size(); i++) {
                v.push_back(temp[i]);
            }
        }
        v.push_back(root->val);
        if(root->right != NULL) {
            vector<int> temp;
            temp = inorderTraversal(root->right);
            for(int i = 0; i < temp.size(); i++) {
                v.push_back(temp[i]);
            }
        }
        return v;
    }
};