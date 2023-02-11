class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {

        vector<int> ans;
        unordered_map<int, int> checker;

        for(int i=0; i<nums.size(); i++)
        {
            int complement = target-nums[i];
            if(checker.find(nums[i])==checker.end()) //element not in hashable
            {
                checker.insert(pair<int, int>(nums[i],i));
            }
            if(checker.find(complement)!=checker.end()) //complement exists in hashtabe
            {
                if(i!=checker[complement])
                {
                    ans.push_back(i);
                    ans.push_back(checker[complement]);
                    break;
                }
            }
        }
        return ans;
    }
};