class Solution {
int mod = 1e9 + 7;
private:
    int solve(int day, int delay, int forget, vector<int>& dp){
        if(day == 1) return 1;

        if(dp[day] != -1) return dp[day];

        int ans = 0;
        for(int d=day-forget+1; d<=day-delay; d++){
            if(d < 0) continue;
            ans = (ans + solve(d,delay,forget,dp)) % mod;
        }
        return dp[day] = ans;
    }
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int ans = 0;
        vector<int> dp(n+1,-1);

        for(int day=n-forget+1; day<=n; day++){
            if(day < 0) continue;
            ans = (ans + solve(day,delay,forget,dp)) % mod;
        }
        return ans;
    }
};