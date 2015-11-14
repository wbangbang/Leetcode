/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    struct TreeNode* temp = NULL;
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL) return root;
    if(root->left != NULL && root->left->left == NULL && root->left->right == NULL && root->right == NULL) {
        root->right = root->left;
        root->left = NULL;
        return root;
    }
    if(root->left == NULL && root->right->left == NULL && root->right->right == NULL && root->right != NULL) {
        root->left = root->right;
        root->right = NULL;
        return root;
    }
    
    root->left = invertTree(root->left);
    root->right = invertTree(root->right);
    temp = root->left;
    root->left = root->right;
    root->right = temp;
    return root;
    
}