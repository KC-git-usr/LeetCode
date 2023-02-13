class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int size_s1 = s1.size(), size_s2 = s2.size();
        if(size_s1 > size_s2)
            return false;

        vector<int> freq_count_s1(26, 0);
        vector<int> freq_count_s2(26, 0);
        int count = 0;

        for(int i = 0; i < size_s1; ++i) {
            freq_count_s1[s1[i] - 'a']++;
            freq_count_s2[s2[i] - 'a']++; // calc only for the sub_str of s2
        }
        for(int i = 0; i < 26; ++i)
            if(freq_count_s1[i] == freq_count_s2[i])
                count++;

        int left_ptr = 0;
        for(int i = size_s1; i < size_s2; ++i) {
            if(count == 26)
                return true;
            freq_count_s2[s2[i] - 'a']++;
            if(freq_count_s2[s2[i] - 'a'] == freq_count_s1[s2[i] - 'a']) {
                count++;
            } else if(freq_count_s2[s2[i] - 'a'] == (freq_count_s1[s2[i] - 'a'] + 1)){
                count--;
            }
            freq_count_s2[s2[left_ptr] - 'a']--;
            if(freq_count_s2[s2[left_ptr] - 'a'] == freq_count_s1[s2[left_ptr] - 'a']) {
                count++;
            } else if(freq_count_s2[s2[left_ptr] - 'a'] == (freq_count_s1[s2[left_ptr] - 'a'] - 1)){
                count--;
            }
            left_ptr++;
        }

        return (count == 26);
    }
};