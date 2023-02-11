class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_set;

        for(size_t i=0; i<nums.size(); i++) {
            if(hash_set.find(nums[i])==hash_set.end()) { //element not in hash_set
                hash_set.insert(nums[i]);
                continue;
            }
            return true;
        }
        return false;
    }
};