/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> s;
    TreeNode* curr = NULL;
public:
    BSTIterator(TreeNode *root) {
        curr = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        curr = temp->right;
        return temp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */