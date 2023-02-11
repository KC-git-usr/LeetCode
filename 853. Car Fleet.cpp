// d = [10,8,0,5,3]
// s = [2,4,1,1,3]
// D = [2,4,12,7,9]
// t = [1,1,12,7,3]

// d = [0,2,4]
// s = [4,2,1]
// D = [100,98,106]
// t = [25,49,106]
// rt = [106,49,25]

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        const int n = position.size();

        if(n == 1)
            return 1;

        // time, position
        vector<pair<float, int>> time_to_target (n, {0.0f, 0});

        for(int i  = 0; i < n; ++i) {
            time_to_target[i].first = (target - position[i] + 0.0f) / speed[i];
            time_to_target[i].second = position[i];
        }

        // sort based on original position
        sort(time_to_target.begin(), time_to_target.end(), [](auto& left, auto& right) {return left.second > right.second;});

        int count = 1;
        float front_of_fleet = time_to_target[0].first;
        for(int i  = 1; i < n; ++i) {
            if(time_to_target[i].first > front_of_fleet) {
                front_of_fleet = time_to_target[i].first;
                count++;
            }
        }
        return count;
    }
};