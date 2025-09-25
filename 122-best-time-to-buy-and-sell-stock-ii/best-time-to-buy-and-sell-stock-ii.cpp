class Solution {
private:
    int solve(int i, vector<int>& prices, int n, bool buy, vector<vector<int>>& dp){
        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];

        int op1 = 0, op2 = 0;
        if(buy){
            op1 = max(-prices[i] + solve(i+1,prices,n,false,dp), solve(i+1,prices,n,true,dp));
        }
        else{
            op2 = max(prices[i] + solve(i+1,prices,n,true,dp), solve(i+1,prices,n,false,dp));
        }

        return dp[i][buy] = max(op1,op2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return solve(0,prices,n,true,dp);
    }
};