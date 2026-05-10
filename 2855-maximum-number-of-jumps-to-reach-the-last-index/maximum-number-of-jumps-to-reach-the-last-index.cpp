class Solution {
private:
    int solve(int i, int j, vector<int>& nums, int target, vector<vector<int>>& dp, int n){
        if(i >= n-1) return 0;
        if(j >= n) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int val = nums[j] - nums[i];
        int op1 = solve(i,j+1,nums,target,dp,n);
        int op2 = -1e9;
        if(val >= -1 * target && val <= target){
            op2 = 1 + solve(j,j+1,nums,target,dp,n);
        }

        return dp[i][j] = max(op1,op2);
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        int ans = solve(0,1,nums,target,dp,n);
        return ans <= -1 ? -1 : ans;
    }
};