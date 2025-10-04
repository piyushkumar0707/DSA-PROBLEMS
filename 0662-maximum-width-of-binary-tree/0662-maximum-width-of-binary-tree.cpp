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
    
int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;

    // Queue stores pairs of TreeNode* and its index in a complete binary tree
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        unsigned long long left = q.front().second;
        unsigned long long right = left; // initialize right to left

        for (int i = 0; i < levelSize; ++i) {
            auto [node, idx] = q.front(); q.pop();
            right = idx;

            if (node->left)
                q.push({node->left, 2 * idx});
            if (node->right)
                q.push({node->right, 2 * idx + 1});
        }

        maxWidth = max(maxWidth, static_cast<int>(right - left + 1));
    }

    return maxWidth;
}

};