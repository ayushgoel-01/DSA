class Solution {
int M = 1e9 + 7;
vector<vector<int>> dp;
private:
    int solve(int n, int prevIdx, vector<string>& states){
        if(n == 0) return 1;

        if(dp[n][prevIdx] != -1) return dp[n][prevIdx];

        string prev = states[prevIdx];

        int ways = 0;
        for(int i=0; i<12; i++){
            if(i == prevIdx) continue;

            string curr = states[i];
            bool flag = true;

            for(int j=0; j<3; j++){
                if(prev[j] == curr[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ways = (ways + solve(n-1,i,states)) % M;
        }
        return dp[n][prevIdx] = ways;
    }
public:
    int numOfWays(int n) {
        vector<string> states = {"RYG","RGY","RYR","RGR","YRG","YGR","YGY","YRY","GYR","GRY",
        "GRG", "GYG"};

        int ans = 0;
        dp = vector<vector<int>>(n+1,vector<int>(12,-1));

        for(int i=0; i<12; i++){
            ans = (ans + solve(n-1,i,states)) % M;
        }
        return ans;
    }
};