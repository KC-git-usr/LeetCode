// Sliding window approach, if new char then expand, else contract

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n <= 1)
            return n;

        unordered_set<char> hash_set;
        int i = 0, j = 0;
        int result = 0;
        while(j < n) {
            // loop until repeated element to removed
            while(hash_set.find(s[j]) != hash_set.end()) {
                hash_set.erase(s[i]);
                i++;
            }
            hash_set.insert(s[j]);
            result = max(result, (j - i + 1));
            j++;
        }
        return result;
    }
};