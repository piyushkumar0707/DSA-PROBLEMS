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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)return false;
        return isSameTree(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        
    }

    bool isSameTree(TreeNode* root, TreeNode* subroot){
        if(root==nullptr && subroot==nullptr)return true;
        if(root==nullptr || subroot==nullptr)return false;
        return(root->val==subroot->val) && isSameTree(root->left, subroot->left) && isSameTree(root->right, subroot->right);
    }
};