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
    unordered_map<int, int> iMap;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.empty() || (inorder.size() != preorder.size())) return NULL;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            iMap[inorder[i]] = i; 
        }
        return build(inorder, preorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& preorder, int si, int ei, int sp, int ep) {
        if(ei < si || ep < sp) return NULL;
        TreeNode* root = new TreeNode(preorder[sp]);
        int rootIndex;
        if(iMap.find(root->val) == iMap.end()) {
            return NULL;
        }
        else {
            rootIndex = iMap[root->val];
        }
        int leftSize = rootIndex - si, rightSize = ei - rootIndex;
        root->left = build(inorder, preorder, si, rootIndex - 1, sp + 1, sp + leftSize);
        root->right = build(inorder, preorder, rootIndex + 1, ei, ep - rightSize + 1, ep);
        return root;
    }
};