// Things i learnt:
// use continue in if statements if the iterator is being altered
// use min/max instead of ?:

class Solution {
public:
    int maxArea(vector<int>& height) {
        int kSize = height.size();
        int left_ptr = 0, right_ptr = (kSize - 1);
        int area = 0, max_area = 0;

        while(left_ptr < right_ptr) {
            area = (right_ptr - left_ptr) * min(height[right_ptr], height[left_ptr]);
            max_area = max(max_area, area);
            if(height[left_ptr] < height[right_ptr]) {
                left_ptr++;
                continue;
            }
            if(height[left_ptr] > height[right_ptr]) {
                right_ptr--;
                continue;
            }
            if(height[left_ptr] == height[right_ptr]) {
                if(height[left_ptr + 1] > height[right_ptr - 1])
                    left_ptr++;
                else
                    right_ptr--;

            }
        }
        return max_area;
    }
};