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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base Case: If tree is empty
        if (root == NULL) return NULL;

        // Step 1: SEARCH for the node
        if (key < root->val) {
            root->left = deleteNode(root->left, key); // Go Left
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key); // Go Right
        } 
        // Step 2: Node FOUND (root->val == key). Perform Deletion.
        else {
            // Case 1: No child (Leaf) OR Case 2: One child
            if (root->left == NULL) {
                TreeNode* temp = root->right;
                delete root;
                return temp; // Return right child (or NULL if leaf)
            } 
            else if (root->right == NULL) {
                TreeNode* temp = root->left;
                delete root;
                return temp; // Return left child
            }

            // Case 3: Two Children
            // Find the Inorder Successor (Smallest in Right Subtree)
            TreeNode* temp = root->right;
            while (temp->left != NULL) {
                temp = temp->left;
            }

            // Replace the current node's value with the successor's value
            root->val = temp->val;

            // Delete the successor node from the right subtree
            // (Since we moved its value up, the old one is now "extra")
            root->right = deleteNode(root->right, temp->val);
        }
        
        return root;
    }
};