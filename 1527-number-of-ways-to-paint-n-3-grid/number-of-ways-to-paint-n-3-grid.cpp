class Solution {
int mod = 1e9 + 7;
private:
    int solve(int n, int prev, vector<string>& v, vector<vector<int>>& dp){
        if(n == 0) return 1;

        if(dp[n][prev] != -1) return dp[n][prev];

        int ans = 0;
        for(int curr=0; curr<12; curr++){
            if(prev == curr) continue;
            bool flag = false;

            for(int j=0; j<3; j++){
                if(v[prev][j] == v[curr][j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans = (ans + solve(n-1,curr,v,dp))%mod;
            }
        }
        return dp[n][prev] = ans;
    }
public:
    int numOfWays(int n) {
        vector<string> v = {"RYG","RYR","RGR","RGY","YRG","YRY","YGR","YGY","GRY","GYR","GYG","GRG"};

        int ans = 0;
        vector<vector<int>> dp(n+1, vector<int>(13,-1));
        for(int i=0; i<12; i++){
            ans = (ans + solve(n-1,i,v,dp))%mod;
        }
        return ans;
    }
};