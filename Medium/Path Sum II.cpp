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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        find(root, sum , temp, res);
        return res;
    }
    
    void find(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& res) {
        if(!root) return;
        sum -= root->val;
        temp.push_back(root->val);
        if(!root->left && !root->right) {
            if(!sum) {
                res.push_back(temp);
            }
        }
        else {
            find(root->left, sum, temp, res);
            find(root->right, sum, temp, res);
        }
        temp.pop_back();
    }
};