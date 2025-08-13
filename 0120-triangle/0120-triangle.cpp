class Solution {
private:
    int rec(vector<vector<int>> &dp, vector<vector<int>> &triangle, int x, int i) {
        if (x < 0)
            return 0;
        if (i < 0 || i > x)
            return INT_MAX; // invalid index in triangle

        if (dp[x][i] != -1)
            return dp[x][i];

        return dp[x][i] = triangle[x][i] +
                          min(rec(dp, triangle, x - 1, i - 1),
                              rec(dp, triangle, x - 1, i));
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int globmin = INT_MAX; // find minimum, not maximum
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) {
            globmin = min(globmin, rec(dp, triangle, n - 1, i));
        }
        return globmin;
    }
};
