class Solution {
private:
    vector<pair<int,int>> directions={{0,1},{1,0},{0,-1},{-1,0}};

    int rec(vector<vector<int>> &matrix,vector<vector<int>> &dp,int i,int j,int m,int n){

        if(dp[i][j]!=-1)
            return dp[i][j];

        for(auto dir:directions){
            int newx=i+dir.first;
            int newy=j+dir.second;
            if(newx>=0&&newy>=0&&newx<n&&newy<m&&matrix[newx][newy]>matrix[i][j]){
                dp[i][j]=max(dp[i][j],1+rec(matrix,dp,newx,newy,m,n));
            }
        }

        if(dp[i][j]==-1)
            return dp[i][j]=0;
        else
            return dp[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int ma=0;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int> (m,-1)),vis;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j]!=-1){
                    ma=max(ma,dp[i][j]);
                }
                else{
                    ma=max(ma,rec(matrix,dp,i,j,m,n));
                }
            }
        }

        return ma+1;
    }
};