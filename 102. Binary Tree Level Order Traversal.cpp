// TIL : C++ has both deque and queue
// TIl : using my_queue.size() within the loop is bad cause size can change within the loop!

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
    vector<vector<int>> BFS(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> curr_lvl_result;
        int curr_lvl_nodes;

        queue<TreeNode*> my_queue;
        my_queue.push(root);
        while(!my_queue.empty()) {
            curr_lvl_nodes = my_queue.size();
            for(int i = 0; i < curr_lvl_nodes; ++i) {
                curr_lvl_result.push_back(my_queue.front()->val);
                if(my_queue.front()->left)
                    my_queue.push(my_queue.front()->left);
                if(my_queue.front()->right)
                    my_queue.push(my_queue.front()->right);
                my_queue.pop();
            }
            result.push_back(curr_lvl_result);
            curr_lvl_result.clear();
        }
        return result;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        return BFS(root);
    }
};