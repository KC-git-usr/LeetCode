// Key : initialize result with n and perform successive XORs with result, i and nums[i]
// from XOR of i and nums[i], we get the difference b/w n and the missing number
// hence we must XOR with n again

// Use the fact that XOR is its own inverse
// Ex. [0,1,3,4]
// Missing = 4^(0^0)^(1^1)^(2^3)^(3^4)
//         = (4^4)^(0^0)^(1^1)^(3^3)^2
//         = 0^0^0^0^2 = 2

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int kSize = nums.size();
        int result = kSize;

        for(int i = 0; i < kSize; ++i)
            result ^= i^nums[i];

        return result;
    }
};