class Solution {
private:
    void solve(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& vis, int n, int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j] = true;

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && 
                grid[nrow][ncol] == '1'){
                    q.push({nrow,ncol});
                    vis[nrow][ncol] = true;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m,false));

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    ans++;
                    solve(i,j,grid,vis,n,m);
                }
            }
        }
        return ans;
    }
};