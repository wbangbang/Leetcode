/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res = "";
        if(!root) res += "#";
        else res += to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return des(data);
    }
    TreeNode* des(string& data) {
        if(data[0] == '#') {
            if(data.size() > 1) data = data.substr(2);
            return NULL;
        }
        TreeNode* root = new TreeNode(toNum(data));
        root->left = des(data);
        root->right = des(data);
        return root;
    }
    
    int toNum(string& data) {
        unsigned int pos = data.find(',');
        int val = stoi(data.substr(0, pos));
        data = data.substr(pos + 1);
        return val;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

