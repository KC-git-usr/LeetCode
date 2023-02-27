class Solution {
private:
    void DFS(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& curr_subset, int index) {
        if(target == 0)
            result.push_back(curr_subset);
        else if(target < 0)
            return;
        else {
            for(int i = index; i < candidates.size(); ++i) {
                if((i > index) && (candidates[i] == candidates[i - 1]))
                    continue;
                curr_subset.push_back(candidates[i]);
                DFS(candidates, target - candidates[i], result, curr_subset, i + 1);
                curr_subset.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr_subset;
        DFS(candidates, target, result, curr_subset, 0);
        return result;
    }
};