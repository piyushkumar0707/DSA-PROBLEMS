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
    unordered_map<int, int> inorderIndex;

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // Map each value to its index in inorder for O(1) lookups
        for (int i = 0; i < inorder.size(); ++i) {
            inorderIndex[inorder[i]] = i;
        }

        // Start from the last index in postorder
        int postIndex = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, postIndex);
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int inLeft, int inRight, int& postIndex) {
        if (inLeft > inRight) return nullptr;

        // The current root is the last element in postorder
        int rootVal = postorder[postIndex--];
        TreeNode* root = new TreeNode(rootVal);

        // Find the index of the root in inorder
        int index = inorderIndex[rootVal];

        // Build right subtree first (postorder pops from end)
        root->right = build(inorder, postorder, index + 1, inRight, postIndex);
        root->left = build(inorder, postorder, inLeft, index - 1, postIndex);

        return root;
    }
};
