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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* current = root;
        
        while (current) {
            if (p->val < current->val && q->val < current->val) {
                current = current->left; // Both nodes are in the left subtree
            } else if (p->val > current->val && q->val > current->val) {
                current = current->right; // Both nodes are in the right subtree
            } else {
                return current; // Split point found
            }
        }
        
        return nullptr; // Should never be reached if p and q are guaranteed to exist
    }
};