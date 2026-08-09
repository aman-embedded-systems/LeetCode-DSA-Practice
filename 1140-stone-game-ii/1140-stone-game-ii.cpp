class Solution {
    public:
    vector<int> suf;
    vector<vector<int>> memo;
    int n;
    int dp(int i, int m) {
    if (i >= n) return 0;
    if (i + 2*m >= n) return suf[i];
    if (memo[i][m] != -1) return memo[i][m];
    int best = 0;
    for (int x = 1; x <= 2*m; x++) {
    best = max(best, suf[i] - dp(i+x, max(m, x)));
    }
    return memo[i][m] = best;
}
int stoneGameII(vector<int>& piles) {
n = piles.size();
suf.assign(n+1, 0);
for (int i = n-1; i >= 0; i--) suf[i] = suf[i+1] + piles[i];
memo.assign(n+1, vector<int>(n+1, -1));
return dp(0, 1);
}
};