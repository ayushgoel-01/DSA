class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n, vector<int>(m,0));

        for(int j=0; j<m; j++) dp[0][j] = matrix[0][j];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                int op1 = matrix[i][j];
                op1 += (j-1 >= 0) ? dp[i-1][j-1] : 1e9;

                int op2 = matrix[i][j] + dp[i-1][j]; 

                int op3 = matrix[i][j];
                op3 += (j+1 < m) ? dp[i-1][j+1] : 1e9;

                dp[i][j] = min({op1,op2,op3});
            }
        }

        int ans = INT_MAX;
        for(int j=0; j<m; j++){
            ans = min(ans,dp[n-1][j]);
        }
        return ans;
    }
};