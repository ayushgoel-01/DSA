class Solution {
private:
    int solve(int i, int prevIdx, vector<int>& nums, vector<vector<int>>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i][prevIdx+1] != -1) return dp[i][prevIdx+1];

        int take = 0;
        if(prevIdx == -1 || nums[prevIdx] < nums[i]){
            take = 1 + solve(i+1,i,nums,dp);
        }
        int notTake = solve(i+1,prevIdx,nums,dp);

        return dp[i][prevIdx+1] = max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n,-1));
        return solve(0,-1,nums,dp);
    }
};