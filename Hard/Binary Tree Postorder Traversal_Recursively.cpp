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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL) return v;
        if(root->left != NULL) {
            vector<int> temp;
            temp = postorderTraversal(root->left);
            for(int i = 0; i < temp.size(); i++) {
                v.push_back(temp[i]);
            }
        }
        if(root->right != NULL) {
            vector<int> temp;
            temp = postorderTraversal(root->right);
            for(int i = 0; i < temp.size(); i++) {
                v.push_back(temp[i]);
            }
        }
        v.push_back(root->val);
        return v;
    }
};