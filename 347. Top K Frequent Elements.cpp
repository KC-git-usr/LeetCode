// BUCKET SORT
// create a freq map
// put this freq map into a hash-map
// key : freq, value : list of numbers having that freq

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_map; // num, freq
        for(int i = 0; i < nums.size(); ++i)
            freq_map[nums[i]]++;

        // 1 : 3 | 2 : 2 | 3 : 1

        unordered_map<int, vector<int>> bucket; // freq, vector of nums
        for(auto it = freq_map.begin(); it != freq_map.end(); ++it)
            bucket[it->second].push_back(it->first);

        // 3 : 1 | 2 : 2 | 1 : 3

        vector<int> result;
        int count = 0;
        for(int i = nums.size(); i >= 0; --i) {
            if(count >= k)
                break;
            if(!(bucket[i].empty())) {
                count += bucket[i].size();
                result.insert(result.begin(), bucket[i].begin(), bucket[i].end());
            }
        }

        return result;
    }
};