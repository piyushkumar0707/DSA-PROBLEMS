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
    int goodNodes(TreeNode* root) {
        int count=0;
        helper(root, INT_MIN, count);
        return count;
        
    }


void helper(TreeNode* root, int maxSoFar, int &count){
    if(root==nullptr)return ;

    if(root->val >= maxSoFar){
        count++;
    }
    int maxi= max(root->val, maxSoFar);

    helper(root->left, maxi, count);
    helper(root->right, maxi, count);
}
};