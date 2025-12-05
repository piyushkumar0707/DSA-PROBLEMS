/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Global index to track our position in the preorder array
    int i = 0;

    TreeNode* build(vector<int>& preorder, int bound) {
        // Base Case: 
        // 1. If we have processed all elements
        // 2. If the current element exceeds the allowable Upper Bound, 
        //    it means this element does NOT belong to the current subtree. 
        //    It belongs to an ancestor's right subtree.
        if (i == preorder.size() || preorder[i] > bound) {
            return NULL;
        }

        // Create the root with the current value
        TreeNode* root = new TreeNode(preorder[i]);
        i++; // Move to next element

        // Logic:
        // 1. Construct Left Subtree: Elements must be smaller than CURRENT node.
        //    So, pass 'root->val' as the new upper bound.
        root->left = build(preorder, root->val);

        // 2. Construct Right Subtree: Elements must be smaller than the PREVIOUS bound.
        //    (e.g., if parent was 8 and we are at 5 (left child), 
        //     the right child of 5 can be 7, but it must still be < 8).
        root->right = build(preorder, bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        i = 0; // Reset index
        return build(preorder, INT_MAX);
    }
};