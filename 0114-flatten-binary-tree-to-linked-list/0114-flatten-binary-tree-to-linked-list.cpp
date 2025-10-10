/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        // Recursively flatten left and right subtrees
        flatten(root->left);
        flatten(root->right);

        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // Attach left subtree to right and nullify left
        root->left = nullptr;
        root->right = left;

        // Find the tail of the new right subtree
        TreeNode* tail = root;
        while (tail->right) {
            tail = tail->right;
        }

        // Attach original right subtree
        tail->right = right;
    }
};