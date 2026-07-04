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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int>path;
        vector<string>result;
        helper(root, path, result);
        return result;
        
    }
    void helper(TreeNode * root, vector<int>&path, vector<string>&result){
        if(root==nullptr)return;
        path.push_back(root->val);

        if(root->left==nullptr && root->right==nullptr){

            string s="";
            for(int i=0; i<path.size(); i++){
                s+=to_string(path[i]);
                if(i!=path.size()-1) s+= "->";
            }
            result.push_back(s);
        }else{
            helper(root->left, path, result);
            helper(root->right, path, result);
        }
        path.pop_back();
        
    }
};