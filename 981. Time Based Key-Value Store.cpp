// Try binary search for exact match
// if BS fails, our target is in-between 2 numbers
// TIL : if you have a sorted input and want to perform BS, do this check first
// check is target is in-between smallest and largest element


class TimeMap {
public:
    // key = key, value = vector of pairs
    // pair of time, value
    unordered_map<string, vector<pair<int, string>>> hash_map;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        this->hash_map[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        if(this->hash_map.find(key) == this->hash_map.end())
            return "";

        const int n = this->hash_map[key].size();

        // our largest/last timestamp_prev <= timestamp
        // OR our smallet/first timestamp_prev > timestamp
        if(this->hash_map[key][n - 1].first <= timestamp) {
            return this->hash_map[key][n - 1].second;
        } else if(this->hash_map[key][0].first > timestamp)
            return "";

        int left = 0, right = (n - 1), mid;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(this->hash_map[key][mid].first == timestamp)
                return this->hash_map[key][mid].second;
            if(this->hash_map[key][mid].first > timestamp)
                right = mid - 1;
            else
                left = mid + 1;
        }
        // our target is between two numbers
        if((this->hash_map[key][left].first > timestamp) && (this->hash_map[key][right].first < timestamp))
            return this->hash_map[key][right].second;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */