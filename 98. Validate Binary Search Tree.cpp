// TIL : LONG_MAX, LONG_MIN and INT_MAX, INT_MIN
// Idea : traverse the entire BST and for every node, we check if it's within bounds
// if left_bound < node->val < right_bound then valid BST node
// left_bound for the left node is retained from prev left_bound, but right_bound for left node is updated to root->val
// left_bound for the right node is updated to root->val, but right_bound for the right node is retained from prev right_bound
// uncomment cout statements to understand!!!

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
    bool checker(TreeNode* root, long right_bound, long left_bound) {
        if(!root)
            return true;
        // cout<<left_bound<<" < "<<root->val<<" < "<<right_bound<<endl;
        if(root->val >= right_bound || root->val <= left_bound)
            return false;
        return (checker(root->left, root->val, left_bound) && checker(root->right, right_bound, root->val));
    }
public:
    bool isValidBST(TreeNode* root) {
        return checker(root, LONG_MAX, LONG_MIN);
    }
};