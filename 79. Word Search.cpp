class Solution {
private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j, int& m, int& n) {
        if((i < 0) || (i >= m) || (j < 0) || (j >= n) || (word[index] != board[i][j])) // out of bounds OR letters not matching
            return false;

        if(index == (word.size() - 1))
            return true;

        board[i][j] = '#'; // don't reuse char

        index++;

        if(dfs(board, word, index, (i - 1), j, m, n) ||
           dfs(board, word, index, (i + 1), j, m, n) ||
           dfs(board, word, index, i, (j - 1), m, n) ||
           dfs(board, word, index, i, (j + 1), m, n))
            return true;

        board[i][j] = word[index - 1]; // revert change made to board

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(); // rows
        int n = board[0].size(); // columns

        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(word[0] == board[i][j])
                    if(dfs(board, word, 0, i, j, m, n))
                        return true;
            }
        }
        return false;
    }
};