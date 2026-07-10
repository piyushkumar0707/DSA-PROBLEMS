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
        if(root == nullptr) return "N,";
        
        string result = to_string(root->val) + ",";
        result += serialize(root->left);
        result += serialize(root->right);
        
        return result;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string item;
        while(getline(ss, item, ',')) {
            q.push(item);
        }
        return buildTree(q);
    }
    
    TreeNode* buildTree(queue<string>& q) {
        string val = q.front();
        q.pop();
        
        if(val == "N") return nullptr;
        
        TreeNode* root = new TreeNode(stoi(val));
        root->left = buildTree(q);
        root->right = buildTree(q);
        
        return root;
    }
};