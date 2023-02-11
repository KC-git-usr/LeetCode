// formula : area[i] = min(max_left_ht, max_right_ht) - ht[i]
// in other words : area[i] = (min of the left/right wall) - (height taken by current index)

class Solution {
public:
    int trap(vector<int>& height) {
        const int kSize = height.size();
        if(kSize < 3)
            return 0;

        int start_index = 0, end_index = (kSize - 1);
        while(height[start_index] == 0)
            start_index++;
        while(height[end_index] == 0)
            end_index--;

        vector<int> max_left_ht (kSize, 0);
        vector<int> max_right_ht (kSize, 0);
        int temp_max = 0;
        for(int i = start_index; i <= end_index; ++i) {
            max_left_ht[i] = temp_max;
            temp_max = max(temp_max, height[i]);
        }
        temp_max = 0;
        for(int i = end_index; i >= start_index; --i) {
            max_right_ht[i] = temp_max;
            temp_max = max(temp_max, height[i]);
        }

        int area = 0, result = 0;
        for(int i = start_index; i <= end_index; ++i) {
            area = min(max_left_ht[i], max_right_ht[i]) - height[i];
            result += max(area, 0);
        }

        return result;
    }
};