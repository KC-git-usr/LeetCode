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
    vector<int> BFS(TreeNode* root) {
        vector<int> result;
        queue<TreeNode*> my_queue;
        my_queue.push(root);
        int curr_lvl_nodes;
        while(!my_queue.empty()) {
            curr_lvl_nodes = my_queue.size();
            for(int i = 0; i < curr_lvl_nodes; ++i) {
                if(i == 0)
                    result.push_back(my_queue.back()->val);
                if(my_queue.front()->left)
                    my_queue.push(my_queue.front()->left);
                if(my_queue.front()->right)
                    my_queue.push(my_queue.front()->right);
                my_queue.pop();
            }
        }
        return result;
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        else
            return BFS(root);
    }
};