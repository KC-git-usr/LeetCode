class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int n = nums.size();
        int left = 0, right = (n - 1), mid = (left + right) / 2;
        bool flag = false;
        while(left <= right) {
            if(nums[mid] == target) {
                flag = true;
                break;
            }
            if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
            mid = (left + right) / 2;
        }
        return (flag ? mid : -1);
    }
};