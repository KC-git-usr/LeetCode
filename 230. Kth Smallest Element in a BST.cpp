// Idea : in-order traversal of the BST and simply print the kth element
// Smart move : instead of using k and "count" to count up-to k, we can use k itself by decrementing it, we stop when k == 0
// TIL : the error you get saying no return statement in all possible paths is only for non-void functions

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
    void helper(TreeNode* root, int& k, int& result) {
        if(!root)
            return;

        if(root->left)
            helper(root->left, k, result);

        // cout<<root->val<<" ";
        k--;
        if(k == 0) {
            result = root->val;
            return;
        }

        if(root->right)
            helper(root->right, k, result);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        helper(root, k, result);
        return result;
    }
};