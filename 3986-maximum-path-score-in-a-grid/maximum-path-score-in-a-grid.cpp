class Solution {
private:
    int n, m;
    int solve(int i, int j, vector<vector<int>>& grid, int k, vector<vector<vector<int>>>& dp) {
        if(i == n-1 && j == m-1){
            if(k - (grid[i][j] == 0 ? 0 : 1) >= 0) return grid[i][j];
            return -1e9;
        }
        if(i >= n || j >= m || k < 0) return -1e9;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int cost = grid[i][j] == 0 ? 0 : 1;

        int op1 = -1e9;
        if (k - cost >= 0) {
            op1 = grid[i][j] + solve(i+1,j,grid,k-cost,dp);
        }

        int op2 = -1e9;
        if (k - cost >= 0) {
            op2 = grid[i][j] + solve(i,j+1,grid,k-cost,dp);
        }
        return dp[i][j][k] = max(op1,op2);
    }

public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k+1,-1)));

        int ans = solve(0,0,grid,k,dp);
        return ans < 0 ? -1 : ans;
    }
};