// Very similar to Subsets 1- pick an element and generate every possible subset with that element
// and every possible subset without that element
// For Subsets 2- same approach, but in the subtrees, while branching, we branch into
// 1st branch having 1+ of the duplicate number
// and 2nd branch having 0 of the duplicate number, this is where we skip

class Solution {
private:
    void DFS(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr_subset, int index) {
        result.push_back(curr_subset);

        for(int i = index; i < nums.size(); ++i) {
            if((i > index) && (nums[i] == nums[i - 1]))
                continue;
            curr_subset.push_back(nums[i]);
            DFS(nums, result, curr_subset, i + 1);
            curr_subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> curr_subset;;
        DFS(nums, result, curr_subset, 0);
        return result;
    }
};