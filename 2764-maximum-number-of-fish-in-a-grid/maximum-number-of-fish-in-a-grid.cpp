class Solution {
private:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};
        int ans = 0;

        while(!q.empty()){
            auto [row,col] = q.front();
            q.pop();
            ans += grid[row][col];

            for(int x=0; x<4; x++){
                int nrow = row + delrow[x];
                int ncol = col + delcol[x];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] > 0 &&
                !vis[nrow][ncol]){
                    vis[nrow][ncol] = true;
                    q.push({nrow,ncol});
                }
            }
        }
        return ans;
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));
        int maxi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] > 0 && !vis[i][j]) maxi = max(maxi,solve(i,j,grid,vis));
            }
        }
        return maxi;
    }
};