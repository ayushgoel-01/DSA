class Solution {
int mod = 1e9 + 7;
private:
    int solve(int i, int j, int sum, vector<vector<int>>& grid, int n, int m, int k,
    vector<vector<vector<int>>>& dp){
        if(i == n-1 && j == m-1){
            sum = (sum + grid[i][j])%k;
            return (sum == 0);
        }
        if(i >= n || j >= m) return 0;

        if(dp[i][j][sum] != -1) return dp[i][j][sum];

        long long right = solve(i,j+1,(sum+grid[i][j])%k,grid,n,m,k,dp)%mod;
        long long down = solve(i+1,j,(sum+grid[i][j])%k,grid,n,m,k,dp)%mod;

        return dp[i][j][sum] = (right + down) % mod;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(k,-1)));
        return solve(0,0,0,grid,n,m,k,dp);
    }
};