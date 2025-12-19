class Solution {
long long dp[1001][501][3];
private:
    long long solve(int i, vector<int>& prices, int k, int n, int Case){
        if(i >= n){
            if(Case == 0) return 0;     // Transaction completed
            return INT_MIN;
        }

        if(dp[i][k][Case] != -1) return dp[i][k][Case];

        long long notTake = solve(i+1,prices,k,n,Case);
        long long take = LLONG_MIN;

        if(k > 0){
            if(Case == 1){      // Sell
                take = prices[i] + solve(i+1,prices,k-1,n,0);
            }
            else if(Case == 2){     // Buy
                take = -prices[i] + solve(i+1,prices,k-1,n,0);
            }
            else{       // Fresh Transaction
                take = max(-prices[i] + solve(i+1,prices,k,n,1), prices[i] + solve(i+1,prices,k,n,2));
            }
        }
        return dp[i][k][Case] = max(take,notTake);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,k,n,0);
    }
};