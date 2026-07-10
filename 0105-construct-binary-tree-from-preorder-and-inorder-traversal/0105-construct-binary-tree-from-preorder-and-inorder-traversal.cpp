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
unordered_map<int, int>inorderIndexMap;
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0; i<inorder.size(); i++){
            inorderIndexMap[inorder[i]]=i;
        }
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        
    }

    TreeNode* build(vector<int>& preOrder, int preStart, int preEnd, vector<int>& inOrder, int inStart, int inEnd){
        if(preStart>preEnd)return nullptr;

        int rootVal=preOrder[preStart];         
        TreeNode* root= new TreeNode(rootVal);

        int rootIndex= inorderIndexMap[rootVal];
        int leftSize= rootIndex- inStart;

        root->left= build(preOrder, preStart+1, preStart+leftSize, inOrder, inStart, rootIndex-1);
        root->right= build(preOrder, preStart+leftSize+1,preEnd, inOrder, rootIndex+1, inEnd );

        return root;
    }

    
};