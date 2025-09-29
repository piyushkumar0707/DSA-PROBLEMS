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
    int maxSum = INT_MIN;

    int maxGain(TreeNode* node) {
        if (!node) return 0;

        // Recursively compute max gain from left and right subtrees
        int leftGain = max(0, maxGain(node->left));   // Ignore negative paths
        int rightGain = max(0, maxGain(node->right));

        // Compute path sum passing through current node
        int currentPathSum = node->val + leftGain + rightGain;

        // Update global max if current path is better
        maxSum = max(maxSum, currentPathSum);

        // Return max gain including current node and one subtree
        return node->val + max(leftGain, rightGain);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};