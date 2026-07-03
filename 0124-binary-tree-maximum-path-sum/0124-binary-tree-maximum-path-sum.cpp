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
int sum=INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return sum;
        
    }
    int helper(TreeNode* root){
        if(root==NULL)return 0;
        int leftSum= helper(root->left);
        int rightSum= helper(root->right);

        leftSum= max(leftSum,0);
        rightSum= max(rightSum,0);

        int maxPath= root->val+ leftSum+ rightSum;
        sum= max(sum, maxPath);
        return root->val+ max(leftSum, rightSum);
    }
};