class Solution {
private:
    int f(string &t1,string &t2,int i,int j,vector<vector<int>> &dp){
        if(i<0||j<0) return 0;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(t1[i]==t2[j]){
            return dp[i][j]=1+f(t1,t2,i-1,j-1,dp);
        }
        return dp[i][j]=max(f(t1,t2,i-1,j,dp),f(t1,t2,i,j-1,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size();
        int n=text2.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return f(text1,text2,m-1,n-1,dp);
    }
};