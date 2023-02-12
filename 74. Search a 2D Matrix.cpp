class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int m = matrix.size();
        const int n = matrix[0].size();

        int top = 0, down = (m - 1), mid_column = (top + down) / 2;
        bool column_flag = false;
        while(top <= down) {
            if((matrix[mid_column][0] <= target) && (matrix[mid_column][n - 1] >= target)) {
                column_flag = true;
                break;
            }
            if(matrix[mid_column][0] > target)
                down = mid_column - 1;
            else
                top = mid_column + 1;
            mid_column = (top + down) / 2;
        }

        if(!column_flag)
            return false;

        int left = 0, right = (n - 1), mid_row = (left + right) / 2;
        bool row_flag = false;
        while(left <= right) {
            if(matrix[mid_column][mid_row] == target) {
                row_flag = true;
                break;
            }
            if(matrix[mid_column][mid_row] > target)
                right = mid_row - 1;
            else
                left = mid_row + 1;
            mid_row = (left + right) / 2;
        }

        return row_flag;
    }
};