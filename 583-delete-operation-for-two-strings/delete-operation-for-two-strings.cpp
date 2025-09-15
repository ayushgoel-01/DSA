class Solution {
private:
    int solve(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return 0;
        if(i < 0 || j < 0) return (i < 0) ? (j+1) : (i+1);

        if(dp[i][j] != -1) return dp[i][j];

        int take = 1e9;
        if(s1[i] == s2[j]) take = solve(i-1,j-1,s1,s2,dp);
        int notTake = min(1+solve(i-1,j,s1,s2,dp),1+solve(i,j-1,s1,s2,dp));

        return dp[i][j] = min(take,notTake);
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }
};