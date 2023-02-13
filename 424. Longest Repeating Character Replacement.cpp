// Sliding window
// Keep a freq count
// Expand by default
// Shrink if (len of window - most freq char) > k

// TIL : order of operations is imp, dont change the index before perf calc

class Solution {
public:
    int characterReplacement(string s, int k) {
        const int n = s.size();
        vector<int> freq_count(26, 0);
        int left = 0, right = 0;
        int result = 0;
        while(right < n) {
            freq_count[s[right] - 'A']++;
            auto max_freq = max_element(freq_count.begin(), freq_count.end());
            // invalid window
            if((right - left + 1 - *max_freq) > k) {
                freq_count[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};