// TIL : use make_pair, don't use {} to cast while returning
// Bottom-up approach
// return bool, ht of sub-tree

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
    bool flag = true;
    int DFS(TreeNode* root) {
        if(this->flag == false)
            return -1;
        if(root) {
            int left_ht = DFS(root->left);
            int right_ht = DFS(root->right);
            if(abs(left_ht - right_ht) > 1) {
                this->flag = false;
                return -1;
            }
            return (1 + max(left_ht, right_ht));
        }
        return (0);
    }
public:
    bool isBalanced(TreeNode* root) {
        int temp = DFS(root);
        return this->flag;
    }
};