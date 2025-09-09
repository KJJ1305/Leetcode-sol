class Solution {
private:
    bool wildrec(string &t1,string &t2,int i,int j,vector<vector<int>> &dp){
        if(i<0){
            if(i==j)
                return true;
            if(t2[j]=='*')
                return wildrec(t1,t2,i,j-1,dp);
            else
                return false;
        }

        if(j<0)
            return false;

        if(dp[i][j]!=-1)
            return dp[i][j];

        if(t1[i]==t2[j])
            return dp[i][j]=wildrec(t1,t2,i-1,j-1,dp);
        else{
            if(t2[j]=='*')
                return dp[i][j]=wildrec(t1,t2,i-1,j,dp)||wildrec(t1,t2,i-1,j-1,dp)||wildrec(t1,t2,i,j-1,dp);
            else if(t2[j]=='?')
                return dp[i][j]=wildrec(t1,t2,i-1,j-1,dp);
            else
                return dp[i][j]=false;
        }
    }

public:
    bool isMatch(string s, string p) {
        int m=s.size();
        int n=p.size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return wildrec(s,p,m-1,n-1,dp);
    }
};