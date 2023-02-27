// top-down approach, at every lvl we decide if we wanna add that num or not

class Solution {
private:
    void DFS(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr_subset, int index) {

        if(index >= nums.size()) {
            result.push_back(curr_subset);
            return;
        }

        // call after adding index
        curr_subset.push_back(nums[index]);
        DFS(nums, result, curr_subset, index + 1);

        // call without adding index
        curr_subset.pop_back();
        DFS(nums, result, curr_subset, index + 1);

    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr_subset;
        DFS(nums, result, curr_subset, 0);
        return result;
    }
};