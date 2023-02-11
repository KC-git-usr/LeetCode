/*
[1,2,3,4]
[24,12,8,6]

Pre:
[1,1,2,6]

Post:
[24,12,4,1]

result[i] = Pre[i-1]*Post[i+1]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(),1), post(nums.size(),1);
        vector<int> result(nums.size(),1);

        for(size_t i = 0; i<nums.size(); i++) {
            if(i == 0) {
                pre[0]=nums[0];
                post[nums.size()-1] = nums[nums.size()-1];
                continue;
            }
            pre[i] = pre[i-1] * nums[i];
            post[nums.size()-1-i] = post[nums.size()-i] * nums[nums.size()-1-i];
        }

        for(size_t i = 0; i<nums.size(); i++) {
            if(i == 0 || i == (nums.size()-1)) {
                result[0] = post[1];
                result[nums.size()-1] = pre[nums.size()-2];
                continue;
            }
            result[i] = pre[i-1]*post[i+1];
        }

        return result;
    }
};
