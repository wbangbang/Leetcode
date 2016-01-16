/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {//iterative
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        stack<TreeNode*> st;
        int count = 0;
        TreeNode* temp = root, *result = NULL;
        st.push(temp);
        while(temp->left) {
            temp = temp->left;
            st.push(temp);
        }
        while(!st.empty() && count < k) {
            result = st.top();
            st.pop();
            count++;
            temp = result->right;
            if(temp) st.push(temp);
            while(temp) {
                temp = temp->left;
                if(temp) st.push(temp);
            }
        }
        return result->val;
    }
};

class Solution {//recursive
    int temp, res;
public:
    int kthSmallest(TreeNode* root, int k) {
        temp = k;
        find(root);
        return res;
    }
    
    void find(TreeNode* root) {
        if(!root) return;
        find(root->left);
        temp--;
        if(!temp) {
            res = root->val;
            return;
        }
        find(root->right);
    }
};