// put input into a hash-set
// imagine a number line
// group the sequences
// find the starting number of the sequences
// start counting for each sequence


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for(int i = 0; i < nums.size(); ++i)
            hash_set.insert(nums[i]);

        int count = 0, result = 0;
        for(int i = 0; i < nums.size(); ++i) {

            if(hash_set.find(nums[i] - 1) != hash_set.end()) // not beginning of a sequence
                continue;

            // loop until we reach last element of that sequence
            while(hash_set.find(nums[i] + count) != hash_set.end()) {
                count++;
                result = max(result, count);
            }
            count = 0;
        }
        return result;
    }
};