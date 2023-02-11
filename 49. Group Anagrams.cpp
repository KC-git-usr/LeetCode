// for every str in input vector
// get the key of that string
// insert key and corresponding string to a hash-map
// return just the values of the hash-map

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;
        for(string str : strs) {
            string key = GetKey(str);
            hash_map[key].push_back(str);
        }

        vector<vector<string>> result;
        for(auto it = hash_map.begin(); it != hash_map.end(); ++it)
            result.push_back(it->second);

        return result;
    }
private:
    string GetKey(string str) {
        vector<int> count(26, 0);
        for(int j = 0; j < str.size(); j++)
            count[str[j] - 'a']++;

        string key = "";
        for (int i = 0; i < 26; i++) {
            key.append(to_string(count[i] + 'a')); // we add 'a' so that smaller alphabet + freq does not mistakenly equal to 1 bigger alphabet
        }
        return key;
    }
};