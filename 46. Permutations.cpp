// Idea : at every function call, we fix one element and swap every combination of 2 elements
// the 2 elements are nums[i] and nums[index]
// if index goes out of bounds, we push to result;
// undo my comments to understand more

class Solution {
private:
    // void myPrint(vector<int>& nums) {
    //     for(int num : nums)
    //         cout<<num<<' ';
    //     cout<<endl;
    // }
    void DFS(vector<int>& nums, vector<vector<int>>& result, int start_index) {
        if(start_index == nums.size()) { // index out of bounds
            result.push_back(nums);
            // cout<<"Pushing : ";
            // myPrint(nums);
        }
        for(int i = start_index; i < nums.size(); ++i) {
            swap(nums[i], nums[start_index]); // swap
            DFS(nums, result, start_index + 1);
            swap(nums[i], nums[start_index]); // undo swap
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        DFS(nums, result, 0);
        return result;
    }
};