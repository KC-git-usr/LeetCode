// We loop the stack until we get a decreasing order stack by popping
// input : [73,74,75,71,69,72,76,73]
// stack : []
// result : [0,0,0,0,0,0,0,0]

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int kSize = temperatures.size();
        vector<int> result (kSize, 0);
        stack<pair<int, int>> temperature_stack; // index, temperature

        for(int i = 0; i < kSize; ++i) {
            while((!(temperature_stack.empty())) && (temperature_stack.top().second < temperatures[i])) {
                result[temperature_stack.top().first] = i - temperature_stack.top().first;
                temperature_stack.pop();
            }
            temperature_stack.push({i, temperatures[i]});
        }
        return result;
    }
};