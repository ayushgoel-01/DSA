class Solution {
private:
    bool solve(int i, int cnt, string& s, vector<vector<int>>& dp){
        if(i >= s.size()) return cnt == 0;

        if(dp[i][cnt] != -1) return dp[i][cnt];

        bool op1 = false, op2 = false, op3 = false;
        if(s[i] == '*'){
            op1 = solve(i+1,cnt+1,s,dp) || solve(i+1,cnt,s,dp);
            if(cnt > 0) op1 = op1 || solve(i+1,cnt-1,s,dp);
        }
        else if(s[i] == '('){
            op2 = solve(i+1,cnt+1,s,dp);
        }
        else if(cnt > 0) op3 = solve(i+1,cnt-1,s,dp);

        return dp[i][cnt] = op1 || op2 || op3;
    }
public:
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return solve(0,0,s,dp);
    }
};