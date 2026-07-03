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
    bool isBalanced(TreeNode* root) {
        if(root==nullptr)return true;
        int leftHeight= maxdepth(root->left);
        int rightHeight= maxdepth(root->right);
        int diff= abs(rightHeight-leftHeight);
        

        bool leftOk= isBalanced(root->left);
        bool rightOk= isBalanced(root->right);
        if(leftOk && rightOk && (diff<=1))return true;

        else return false;

    }

    int maxdepth(TreeNode* root){
        if(root==nullptr)return 0;
        int leftDepth= maxdepth(root->left);
        int rightDepth= maxdepth(root->right);
        int depth= 1+max(leftDepth, rightDepth);
        return depth;

    }
};