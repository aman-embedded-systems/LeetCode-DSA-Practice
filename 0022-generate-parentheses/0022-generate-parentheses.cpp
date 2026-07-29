class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        solve(result, current, 0, 0, n);
        return result;
    }

    void solve(vector<string>& result, string& current, int open, int close, int n) {
        if ((int)current.size() == n * 2) {
            result.push_back(current);
            return;
        }
        if (open < n) {
            current.push_back('(');
            solve(result, current, open + 1, close, n);
            current.pop_back();
        }
        if (close < open) {
            current.push_back(')');
            solve(result, current, open, close + 1, n);
            current.pop_back();
        }
    }
};