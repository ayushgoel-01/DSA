class Solution {
private:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& dp){
        if(i >= n || j >= m) return -1e8;

        int cost = (grid[i][j] == 0 ? 0 : 1);
        if(k < cost) return -1e8;

        if(i == n-1 && j == m-1) return grid[i][j];

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int op1 = solve(i+1,j,grid,k-cost,dp);
        int op2 = solve(i,j+1,grid,k-cost,dp);

        int best = max(op1,op2);

        if(best < 0) return dp[i][j][k] = -1e8;
        return dp[i][j][k] = grid[i][j] + best;
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1, -1)));

        int ans = solve(0,0,grid,k,dp);
        return ans < 0 ? -1 : ans;
    }
};