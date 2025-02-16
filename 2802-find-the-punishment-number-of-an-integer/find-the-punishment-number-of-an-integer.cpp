class Solution {
private:
    bool solve(int i, int currSum, string s, int num, vector<vector<int>>& dp){
        if(i >= s.size()) return currSum == num;
        if(currSum > num) return false;

        if(dp[i][currSum] != -1) return dp[i][currSum];

        bool ans = false;

        for(int j=i; j<s.size(); j++){
            string sub = s.substr(i,j-i+1);
            int val = stoi(sub);

            ans = ans || solve(j+1,currSum+val,s,num,dp);
            if(ans == true) return ans;
        }
        return dp[i][currSum] = ans;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;

        for(int i=1; i<=n; i++){
            int sq = i * i;
            string s = to_string(sq);

            vector<vector<int>> dp(s.size()+1, vector<int>(i+1,-1));
            if(solve(0,0,s,i,dp)) ans += sq;
        }
        return ans;
    }
};