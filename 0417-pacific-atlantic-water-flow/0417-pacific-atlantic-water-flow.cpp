class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        
        // Lambda DFS
        function<void(int,int,vector<vector<bool>>&,int)> dfs = 
        [&](int r, int c, vector<vector<bool>> &visited, int prevHeight) {
            if (r < 0 || r >= m || c < 0 || c >= n) return;
            if (visited[r][c]) return;
            if (heights[r][c] < prevHeight) return; // water can't flow uphill
            visited[r][c] = true;
            static const int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            for (auto &d : dirs) {
                int nr = r + d[0], nc = c + d[1];
                dfs(nr, nc, visited, heights[r][c]);
            }
        };
        
        // Run DFS from Pacific borders (top row and left col)
        for (int c = 0; c < n; ++c) dfs(0, c, pac, INT_MIN);
        for (int r = 0; r < m; ++r) dfs(r, 0, pac, INT_MIN);
        // Run DFS from Atlantic borders (bottom row and right col)
        for (int c = 0; c < n; ++c) dfs(m-1, c, atl, INT_MIN);
        for (int r = 0; r < m; ++r) dfs(r, n-1, atl, INT_MIN);
        
        vector<vector<int>> res;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};