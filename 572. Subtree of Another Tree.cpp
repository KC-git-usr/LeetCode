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
    bool flag = false;
    void getSubRootHead(TreeNode* root, TreeNode* subRoot) {
        if(root) {
            if(flag == true)
                return;
            if(root->val == subRoot->val) {
                flag = treeMatch(root, subRoot);
            }
            getSubRootHead(root->left, subRoot);
            getSubRootHead(root->right, subRoot);
        }
    }
    bool treeMatch(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot)
            return true;
        if(!root || !subRoot)
            return false;
        if(root->val != subRoot->val)
            return false;
        return (treeMatch(root->left, subRoot->left) && treeMatch(root->right, subRoot->right));
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        getSubRootHead(root, subRoot);
        return this->flag;
    }
};