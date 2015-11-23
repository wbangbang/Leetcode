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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        string s = "";                              //initialize the string
        preOrder(root, v, s);
        return v;
    }
    
    void preOrder(TreeNode* root, vector<string>& v, string s) {
        stringstream ss;                                        //transfer an integer to string
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) {
            ss << root->val;
            v.push_back(s + ss.str());
            return;
        }
        ss << root->val;
        preOrder(root->left, v, s + ss.str() + "->");
        preOrder(root->right, v, s + ss.str() + "->");
    }
};