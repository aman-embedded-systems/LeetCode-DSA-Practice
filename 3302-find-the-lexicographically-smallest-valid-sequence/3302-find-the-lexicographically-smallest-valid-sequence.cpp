class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = dp[i + 1];
            if (dp[i] < m && word1[i] == word2[m - 1 - dp[i]]) dp[i]++;
        }
        vector<int> res;
        int i = 0;
        bool used = false;
        for (int j = 0; j < m; j++) {
            bool found = false;
            while (i < n) {
                if (word1[i] == word2[j]) {
                    res.push_back(i);
                    i++;
                    found = true;
                    break;
                } else if (!used && dp[i + 1] >= m - 1 - j) {
                    res.push_back(i);
                    used = true;
                    i++;
                    found = true;
                    break;
                }
                i++;
            }
            if (!found) return {};
        }
        return res;
    }
};