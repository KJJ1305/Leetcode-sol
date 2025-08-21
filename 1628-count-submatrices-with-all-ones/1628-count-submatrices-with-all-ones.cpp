class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
         int n = mat.size(), m = mat[0].size();
    vector<int> height(m, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
        
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) height[j] += 1;
            else height[j] = 0;
        }

        
        stack<int> st;
        vector<int> dp(m, 0);  
        for (int j = 0; j < m; j++) {
            while (!st.empty() && height[st.top()] >= height[j])
                st.pop();

            if (!st.empty()) {
                int prev = st.top();
                dp[j] = dp[prev] + height[j] * (j - prev);
            } else {
                dp[j] = height[j] * (j + 1);
            }
            ans += dp[j];
            st.push(j);
        }
    }
    return ans;
    }
};