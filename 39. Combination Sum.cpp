class Solution {
private:
    int sum(vector<int>& curr_subset) {
        int result = 0;
        for(int num : curr_subset)
            result += num;
        return result;
    }
    void DFS(vector<int>& candidates, int& target, vector<vector<int>>& result, vector<int>& curr_subset, int index) {
        if((index >= candidates.size()) || (sum(curr_subset) > target)) {
            return;
        }
        if(sum(curr_subset) == target) {
            result.push_back(curr_subset);
        } else {
            curr_subset.push_back(candidates[index]);
            DFS(candidates, target, result, curr_subset, index);

            curr_subset.pop_back();
            DFS(candidates, target, result, curr_subset, index + 1);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr_subset;
        DFS(candidates, target, result, curr_subset, 0);
        return result;
    }
};