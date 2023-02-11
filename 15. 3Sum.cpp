// sort input array
// for every ele in sorted array
// perform two sum ll on the rest of the sorted array

// [-4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0]
// [-5, -5, -4, -4, -4, -2, -2, -2, 0, 0, 0, 1, 1, 3, 4, 4]

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        if(nums[0] > 0)
            return {};

        int kSize = nums.size();
        int target, left_ptr, right_ptr, sum;
        vector<vector<int>> result;

        for(int i = 0; i < kSize - 2; ++i) {

            target = -1 * nums[i];
            left_ptr = i + 1 ;
            right_ptr = kSize - 1;

            if((i > 0) && (nums[i - 1] == nums[i])) // if we find a repeating target then skip
                continue;

            while(left_ptr < right_ptr) {
                sum = nums[left_ptr] + nums[right_ptr];
                if(sum == target) {
                    result.push_back({nums[i], nums[left_ptr], nums[right_ptr]});
                    while((left_ptr < right_ptr) && (nums[left_ptr] == nums[left_ptr + 1]))
                        left_ptr++;
                    left_ptr++;
                    while((left_ptr < right_ptr) && (nums[right_ptr] == nums[right_ptr - 1]))
                        right_ptr--;
                    right_ptr--;
                }
                if(sum > target) {
                    right_ptr--;
                }
                if(sum < target) {
                    left_ptr++;
                }
            }
        }
        return result;
    }
};