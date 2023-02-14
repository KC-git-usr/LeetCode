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
private:
    void treeTrversal(TreeNode* root) {
        // pre-order : L, M, R
        // in-order : M, L, R *
        // post-order : R, M, L
        if(root == nullptr) {
            return;
        } else {
            TreeNode* temp = root->left;
            root->left = root->right;
            treeTrversal(root->left);
            root->right = temp;
            treeTrversal(root->right);
        }
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        treeTrversal(root);
        return root;
    }
};