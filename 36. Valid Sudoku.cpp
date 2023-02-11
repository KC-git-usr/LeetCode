class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        const int kSize = 9;
        bool rows[kSize][kSize] {false};
        bool columns[kSize][kSize] {false};
        bool sub_boxes[kSize][kSize] {false};

        for(int r = 0; r < kSize; ++r) {
            for(int c = 0; c < kSize; ++c) {
                if(board[r][c] == '.')
                    continue;

                int num = board[r][c] - '0' -1; // converting to int and off-setting by 1 to account for array index bounds
                int sub_box_index = (r / 3) * 3 + (c / 3); // see solutions for explanation of sub_box_index

                if(rows[r][num] || columns[c][num] || sub_boxes[sub_box_index][num])
                    return false;

                rows[r][num] = true;
                columns[c][num] = true;
                sub_boxes[sub_box_index][num] = true;
            }
        }
        return true;
    }
};