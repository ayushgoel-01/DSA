class Solution {
private:
    int solve(int i, vector<int>& prices, int n, bool buy, int cnt, vector<vector<vector<int>>>& dp){
        if(i >= n || cnt <= 0) return 0;

        if(dp[i][buy][cnt] != -1) return dp[i][buy][cnt];

        int op1 = 0, op2 = 0;
        if(buy){
            op1 = max(-prices[i] + solve(i+1,prices,n,false,cnt,dp), 
                                    solve(i+1,prices,n,true,cnt,dp));
        }
        else{
            op2 = max(prices[i] + solve(i+1,prices,n,true,cnt-1,dp), solve(i+1,prices,n,false,cnt,dp));
        }

        return dp[i][buy][cnt] = max(op1,op2);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3,-1)));
        return solve(0,prices,n,true,2,dp);
    }
};