class Solution {
private:
    int solve(int i, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(i < 0) return target == 0;

        if(dp[i][target+2000] != -1) return dp[i][target+2000];

        int plus = solve(i-1,nums,target+nums[i],dp);
        int minus = solve(i-1,nums,target-nums[i],dp);

        return dp[i][target+2000] = plus + minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target+20000,-1));
        return solve(n-1,nums,target,dp);
    }
};