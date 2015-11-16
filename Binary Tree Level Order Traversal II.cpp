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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> w;
        stack<vector<int>> s;
        queue<TreeNode*> q;
        TreeNode* temp = NULL;
        if(root == NULL) {
            return w;
        }
        q.push(root);
        while(!q.empty()) {
            vector<int> v;
            int j = q.size();                               //the size of queue varies, so to store its initial value is needed.
            for(int i = 0; i < j; i++) {
                temp = q.front();
                v.push_back(temp->val);
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                q.pop();
            }
            s.push(v);
        }
        while(!s.empty()) {
            w.push_back(s.top());
            s.pop();
        }
        return w;
    }
};