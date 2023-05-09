// bit-wise xor with every element and the cumulative result (result was initialized with 0)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        const int kSize = nums.size();

        if(kSize == 1)
            return nums[0];

        int result = 0;
        for(int i = 0; i < nums.size(); ++i) {
            result ^= nums[i];
        }
        return (result);
    }
};