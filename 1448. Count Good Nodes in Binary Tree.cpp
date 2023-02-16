// TIL : passing by ref for DFS/BFS can be a mistake

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
    void DFS(TreeNode* root, int curr_max, int& result) { // mistake is passing by ref
        if(!root)
            return;
        curr_max = max(curr_max, root->val);
        if(root->val < curr_max) { // bad node
            // do nothing
        } else { // good node, so inc count
            result++;
        }
        DFS(root->left, curr_max, result);
        DFS(root->right, curr_max, result);
    }
public:
    int goodNodes(TreeNode* root) {
        if(!root->left && !root->right)
            return 1;
        int result = 0;
        DFS(root, root->val, result);
        return result;
    }
};