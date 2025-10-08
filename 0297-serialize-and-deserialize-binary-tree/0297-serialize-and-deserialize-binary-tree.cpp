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
        string result;
        serializeHelper(root, result);
        return result;
    }

    // Helper for serialization
    void serializeHelper(TreeNode* node, string& result) {
        if (!node) {
            result += "#,";
            return;
        }
        result += to_string(node->val) + ",";
        serializeHelper(node->left, result);
        serializeHelper(node->right, result);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')) {
            tokens.push(token);
        }
        return deserializeHelper(tokens);
    }

    // Helper for deserialization
    TreeNode* deserializeHelper(queue<string>& tokens) {
        if (tokens.empty()) return nullptr;

        string val = tokens.front();
        tokens.pop();

        if (val == "#") return nullptr;

        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeHelper(tokens);
        node->right = deserializeHelper(tokens);
        return node;
    }
};