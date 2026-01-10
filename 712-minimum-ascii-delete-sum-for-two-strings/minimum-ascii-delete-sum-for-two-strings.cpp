class Solution {
private:
    int solve(int i, int j, string& s1, string& s2, int n, int m, vector<vector<int>>& dp){
        if(i >= n && j >= m) return 0;
        if(i >= n) return s2[j] + solve(i,j+1,s1,s2,n,m,dp);
        if(j >= m) return s1[i] + solve(i+1,j,s1,s2,n,m,dp);

        if(dp[i][j] != -1) return dp[i][j];

        int take = INT_MAX;
        if(s1[i] == s2[j]){
            take = solve(i+1,j+1,s1,s2,n,m,dp);
        }

        int notTake = min(s1[i] + solve(i+1,j,s1,s2,n,m,dp),s2[j] + solve(i,j+1,s1,s2,n,m,dp));

        return dp[i][j] = min(take,notTake);
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(0,0,s1,s2,n,m,dp);
    }
};