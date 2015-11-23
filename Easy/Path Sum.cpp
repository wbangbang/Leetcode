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
    bool hasPathSum(TreeNode* root, int sum) {
        vector<int> v;
        int s = 0;
        pathSum(root, v, s);
        if(v.size() == 0) return NULL;
        for(int i = 0; i < v.size(); i++) {
            if(sum == v[i]) return true;
        }
        return false;
    }
    
    void pathSum(TreeNode* root, vector<int>& v, int sum) {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            sum += root->val;
            v.push_back(sum);
            return;
        }
        sum += root->val;
        pathSum(root->left, v, sum);
        pathSum(root->right, v, sum);
    }
};