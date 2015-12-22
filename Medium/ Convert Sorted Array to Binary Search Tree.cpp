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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty()) return NULL;
        /*vector<int> left,right; // Avoid building new vector! 
        for(int i = 0; i < mid; i++) {
            left.push_back(nums[i]);
        }
        for(int i = mid + 1; i < n; i++) {
            right.push_back(nums[i]);
        }*/
        return AtoB(nums, 0, nums.size() - 1);
    }
    
    TreeNode* AtoB(vector<int>& nums, int l, int r) {
        if(r < l) return NULL;
        int mid = (l + r) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = AtoB(nums, l, mid - 1);
        root->right = AtoB(nums, mid + 1, r);
        return root;
    }
};