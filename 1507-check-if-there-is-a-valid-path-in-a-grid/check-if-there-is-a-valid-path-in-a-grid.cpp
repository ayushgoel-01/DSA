class Solution {
private:
    int n, m;
    unordered_map<int,vector<vector<int>>> dir = {
        {1, {{0,-1}, {0,1}}},
        {2, {{-1,0}, {1,0}}},
        {3, {{0,-1}, {1,0}}},
        {4, {{0,1}, {1,0}}},
        {5, {{-1,0}, {0,-1}}},
        {6, {{-1,0}, {0,1}}}
    };

    bool dfs(int row, int col, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        if(row == n-1 && col == m-1) return true;

        vis[row][col] = true;

        for(auto& it: dir[grid[row][col]]){
            int nrow = row + it[0];
            int ncol = col + it[1];

            if(nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || vis[nrow][ncol]){
                continue;
            }

            // Check can we come to {row,col} cell again
            for(auto& backDir: dir[grid[nrow][ncol]]){
                if(nrow + backDir[0] == row && ncol + backDir[1] == col){
                    if(dfs(nrow,ncol,grid,vis)) return true;
                }
            }
        }
        return false;
    }

public:
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        return dfs(0,0,grid,vis);
    }
};