class Solution {
private:
    int getZero(string& s){
        int cnt = 0;
        for(auto i: s) cnt += i == '0';
        return cnt;
    }

    int getOne(string& s){
        int cnt = 0;
        for(auto i: s) cnt += i == '1';
        return cnt;
    }

    int solve(int i, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp){
        if(i >= strs.size()) return 0;

        if(dp[i][m][n] != -1) return dp[i][m][n];

        int cnt1 = getZero(strs[i]);
        int cnt2 = getOne(strs[i]);
        int take = 0;

        if(cnt1 <= m && cnt2 <= n){
            take = 1 + solve(i+1,strs,m-cnt1,n-cnt2,dp);
        }
        int notTake = solve(i+1,strs,m,n,dp);

        return dp[i][m][n] = max(take,notTake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size, vector<vector<int>>(m+1, vector<int>(n+1,-1)));
        return solve(0,strs,m,n,dp);
    }
};