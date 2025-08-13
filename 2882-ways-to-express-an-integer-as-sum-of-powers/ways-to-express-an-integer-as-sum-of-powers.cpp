class Solution {
int mod = 1e9 + 7;
private:
    int solve(int n, int x, int i, vector<vector<int>>& dp){
        if(n == 0) return 1;
        if(n < 0 || pow(i,x) > n) return 0;

        if(dp[n][i] != -1) return dp[n][i];

        int take = 0, notTake = 0;
        take = (take + solve(n-pow(i,x),x,i+1,dp)%mod)%mod;
        notTake = (notTake + solve(n,x,i+1,dp)%mod)%mod;

        return dp[n][i] = (take + notTake) % mod;
    }
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(301, vector<int>(301,-1));
        return solve(n,x,1,dp);
    }
};