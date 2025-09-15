class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1,0));

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                int take = 0;
                if(s[i-1] == t[j-1]) take = 1 + dp[i-1][j-1];
                int notTake = max(dp[i-1][j],dp[i][j-1]);

                dp[i][j] = max(take,notTake);
            }
        }
        return n - dp[n][n];
    }
};