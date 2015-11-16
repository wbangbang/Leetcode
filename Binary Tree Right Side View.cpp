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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        queue<TreeNode*> q;
        TreeNode* temp = NULL;
        if(root == NULL) {
            return v;
        }
        q.push(root);
        while(!q.empty()) {
            int j = q.size();                               
            for(int i = 0; i < j; i++) {
                temp = q.front();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                if(i == j - 1) v.push_back(temp->val);
                q.pop();
            }
        }
        return v;
    }
};