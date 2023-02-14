// Bottom-Up approach
// For every node, calc the dia and ht for that node
// ht of node = 1 + max(ht_left_node, ht_right_node) with base case being if node == nullptr return -1
// dia of node = ht_left_node + ht_right_node + 2

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
    int max_diameter = 0;
    int DFS(TreeNode* root) {
        if(root == nullptr)
            return -1; // returning ht as -1 if nullptr
        int left_height = DFS(root->left);
        int right_height = DFS(root->right);
        this->max_diameter = max(this->max_diameter, left_height + right_height + 2);
        int curr_height = 1 + max(left_height, right_height);
        return curr_height;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        DFS(root); // don't forget to call the DFS
        return this->max_diameter;
    }
};