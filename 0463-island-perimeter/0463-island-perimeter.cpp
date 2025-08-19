class Solution {
private:
    vector<pair<int,int>> direct={{0,1},{1,0},{-1,0},{0,-1}};

    int dfs(vector<vector<int>> &grid,vector<vector<int>> &vis,int i,int j,int n,int m){
        
        int sum=4;
        vis[i][j]=1;
        for(auto dir:direct){
            int newx=dir.first+i;
            int newy=dir.second+j;

            if(newx>=0&&newx<n&&newy>=0&&newy<m&&grid[newx][newy]==1){
                sum=sum-1;
                if(vis[newx][newy]==0){
                    sum=sum+dfs(grid,vis,newx,newy,n,m);
                }
            }
        }

        return sum;

    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return dfs(grid,vis,i,j,n,m);
                }
            }
        }

        return 0;
    }
};