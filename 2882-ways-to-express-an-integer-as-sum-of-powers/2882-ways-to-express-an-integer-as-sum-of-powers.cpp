class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD= 1e9+7;

        vector<int> powers;

        for(int i=1; ;i++){
            long long p=pow(i,x);

            if(p>n)
                break;
            powers.push_back(p);
        }

        vector<int> dp(n+1,0);
        dp[0]=1;
        for (int p : powers)
            for (int i = n; i >= p; --i)
                dp[i] = (dp[i] + dp[i - p]) % MOD;
           
            return dp[n];


    }
};