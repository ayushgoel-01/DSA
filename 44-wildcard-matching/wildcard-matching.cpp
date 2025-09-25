class Solution {
private:
    int solve(int i, int j, string& s, string& p, vector<vector<int>>& dp){
        if(i < 0 && j < 0) return true;
        if(j < 0) return false;
        if(i < 0){
            for(int idx=j; idx>=0; idx--){
                if(p[idx] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        bool op1 = false, op2 = false;
        if(s[i] == p[j] || p[j] == '?'){
            op1 = solve(i-1,j-1,s,p,dp);
        }
        else if(p[j] == '*'){
            op2 = solve(i-1,j-1,s,p,dp) || solve(i-1,j,s,p,dp) || solve(i,j-1,s,p,dp);
        }
        return dp[i][j] = op1 || op2;
    }
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return solve(n-1,m-1,s,p,dp);
    }
};