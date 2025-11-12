class Solution {
private:
    int coinsrec(vector<int>& coins, vector<vector<int>>& dp, int target, int ind) {
        if(target == 0) return 0;
        if(ind == 0){
            if(target % coins[0] == 0)
                return target / coins[0];
            else
                return INT_MAX;
        }

        if(dp[ind][target] != -1) return dp[ind][target];  // \U0001f534 Memoization check

        int nottaken = coinsrec(coins, dp, target, ind-1);
        int taken = INT_MAX;
        if(coins[ind] <= target){
            int subres = coinsrec(coins, dp, target-coins[ind], ind);
            if(subres != INT_MAX)  // to avoid overflow
                taken = 1 + subres;
        }

        return dp[ind][target] = min(taken, nottaken);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int res = coinsrec(coins, dp, amount, n-1);
        return (res == INT_MAX) ? -1 : res;
    }
};
