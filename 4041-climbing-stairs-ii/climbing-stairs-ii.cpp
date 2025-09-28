class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+3, 0);

        for(int i=n-1; i>=0; i--){
            int op1 = 1e9, op2 = 1e9, op3 = 1e9;
            op1 = costs[i] + 1 + dp[i+1];
            if(i+1 < n) op2 = costs[i+1] + 4 + dp[i+2];
            if(i+2 < n) op3 = costs[i+2] + 9 + dp[i+3];

            dp[i] = min({op1, op2, op3});
        }
        return dp[0];
    }
};