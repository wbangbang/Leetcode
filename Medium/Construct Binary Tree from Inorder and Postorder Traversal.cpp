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
    unordered_map<int, int> iMap;//makes find-operation faster!
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty() || (inorder.size() != postorder.size())) return NULL;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            iMap[inorder[i]] = i; 
        }
        return build(inorder, postorder, 0, n - 1, 0, n - 1);
    }
    
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int si, int ei, int sp, int ep) {
        if(ei < si || ep < sp) return NULL;
        TreeNode* root = new TreeNode(postorder[ep]);
        int rootIndex;
        if(iMap.find(root->val) == iMap.end()) {
            return NULL;
        }
        else {
            rootIndex = iMap[root->val];
        }
        int leftSize = rootIndex - si, rightSize = ei - rootIndex;
        root->left = build(inorder, postorder, si, rootIndex - 1, sp, sp + leftSize - 1);
        root->right = build(inorder, postorder, rootIndex + 1, ei, ep - rightSize, ep - 1);//Attention the indices.
        return root;
    }
};