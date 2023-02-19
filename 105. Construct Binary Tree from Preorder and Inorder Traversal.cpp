// Idea : extract the root from the preorder, search for it in inorder
// every element immediately after the root node from the preorder array will either be the left or right node
// to determine if the next element from the preorder array is a left or right node, we search for that
// val in the inorder array within certain bounds, if those bounds are valid
// then we found our left or right node, if not, then the left or right node is a nullptr
// how are we deciding the bounds?
// every element to the left of our root in the inorder array, exists to left of the root in the BST too
// similarly, every element to the right of our root in the inorder array, exists to right of the root in the BST too

// pre-order : process root first, call left node and then call right node
// in-roder : call left node, print root node, call right node

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
    TreeNode* buildBST(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if(i > j) {
            // cout<<"Tried to search for num between "<<i<<" and "<<j<<" in inorder array"<<endl;
            return nullptr;
        }

        // cout<<"Searching for "<<preorder[index]<<" between "<<i<<" and "<<j<<" in inorder array"<<endl;

        TreeNode* node = new TreeNode(preorder[index]);

        int split = 0;
        for(int k = 0; k < inorder.size(); ++k) {
            if(preorder[index] == inorder[k])
                split = k;
        }
        index++;

        node->left = buildBST(preorder, inorder, index, i, split - 1);
        node->right = buildBST(preorder, inorder, index, split + 1, j);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return buildBST(preorder, inorder, index, 0, inorder.size() - 1);
    }
};