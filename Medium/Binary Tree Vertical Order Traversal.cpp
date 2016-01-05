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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> myMap;
        vector<vector<int>> res;
        queue<pair<int, TreeNode*>> myQ;
        if(!root) return res;
        myQ.push(make_pair(0, root));
        while(!myQ.empty()) {
            int n = myQ.size();
            TreeNode* temp;
            int hd;
            for(int i = 0; i < n; i++) {
                temp = myQ.front().second;
                hd = myQ.front().first;
                myQ.pop();
                if(temp->left) myQ.push(make_pair(hd - 1, temp->left));
                if(temp->right) myQ.push(make_pair(hd + 1, temp->right));
                myMap[hd].push_back(temp->val);
            }
        }
        if(!myMap.empty()) {
            for(auto i: myMap) {
                res.push_back(i.second);
            }
        }
        return res;
    }
};