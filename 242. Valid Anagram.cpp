class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        // count freq of alphabets
        for(int i=0; i<s.size(); ++i) {
            s_map[s[i]]++;
            t_map[t[i]]++;
        }

        // compare freq map of s with t
        for(auto it=s_map.begin(); it != s_map.end(); ++it) {
            if(s_map[it->first] != t_map[it->first])
                return false;
        }

        return true;
    }
};