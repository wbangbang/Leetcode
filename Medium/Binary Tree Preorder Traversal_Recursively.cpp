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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL) return v;
        v.push_back(root->val);
        if(root->left != NULL) {
            vector<int> temp;
            temp = preorderTraversal(root->left);
            for(int i = 0; i < temp.size(); i++) {
                v.push_back(temp[i]);
            }
        }
        if(root->right != NULL) {
            vector<int> temp;
            temp = preorderTraversal(root->right);
            for(int i = 0; i < temp.size(); i++) {
                v.push_back(temp[i]);
            }
        }
        return v;
    }
};