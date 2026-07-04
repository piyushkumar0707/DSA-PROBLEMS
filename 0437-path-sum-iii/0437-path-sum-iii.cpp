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
unordered_map<long long, int>prefixCount;
    int pathSum(TreeNode* root, int targetSum) {
        prefixCount[0]=1;
        return helper(root, 0, targetSum);
        
    }
    int helper(TreeNode* root, long long currentSum, int target){
        if(root==nullptr)return 0;
        currentSum+=root->val;
        int count= prefixCount[currentSum-target];
        prefixCount[currentSum]++;
        count+=helper(root->left,currentSum,target);
        count+=helper(root->right, currentSum, target);

        prefixCount[currentSum]--;
        return count;


    }
};