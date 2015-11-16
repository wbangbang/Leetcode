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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> w;
        queue<TreeNode*> q;
        TreeNode* temp = NULL;
        int c = 1;
        if(root == NULL) {
            return w;
        }
        q.push(root);
        while(!q.empty()) {
            vector<int> v;
            stack<int> s;
            int j = q.size();                               //the size of queue varies, so to store its initial value is needed.
            for(int i = 0; i < j; i++) {
                temp = q.front();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
                if(c == 1) {
                    v.push_back(temp->val);
                }
                else {
                    s.push(temp->val);
                }
                q.pop();
               
            }
            if(c == -1) {
                while(!s.empty()) {
                    v.push_back(s.top());
                    s.pop();
                }
            }
            w.push_back(v);
            c = -c;
        }
        return w;
    }
};