// backtracking- we are stacking the recursive function calls
// conditions:
// 1. add ( if open < n
// 2. add ) if close < open

class Solution {
private:
    void validParenthesis(int& n, int open, int close, string str, vector<string>& result) {
        if((open == n) && (close == n)) {
            result.push_back(str);
            return;
        }
        if(open < n)
            validParenthesis(n, open + 1, close, str + "(", result);
        if(close < open)
            validParenthesis(n, open, close + 1, str + ")", result);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        validParenthesis(n, 0, 0, "", result);
        return result;
    }
};