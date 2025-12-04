class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Traverse until we hit NULL or find the value
        while (root != nullptr && root->val != val) {
            
            // If the target value is smaller, go left
            if (val < root->val) {
                root = root->left;
            } 
            // If the target value is larger, go right
            else {
                root = root->right;
            }
        }
        
        // Return the found node or NULL if loop ended
        return root;
    }
};