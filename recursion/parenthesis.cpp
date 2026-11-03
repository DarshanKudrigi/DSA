// leetcode 22 

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(n,n,current,result);
        return result;
    }
private:
    void backtrack(int open, int close, string current, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }
        if (open > 0) {
            backtrack(open - 1, close, current + "(", result);
        }
        if (close > 0 && close > open) {
            backtrack(open, close - 1, current + ")", result);
        }
    }
};