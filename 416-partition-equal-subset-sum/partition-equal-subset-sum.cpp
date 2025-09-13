class Solution {
private:
    bool solve(int i, vector<int>& nums, int target, int n, vector<vector<int>>& dp){
        if(i >= n) return target == 0;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = false;
        if(nums[i] <= target) take = solve(i+1,nums,target-nums[i],n,dp);

        bool notTake = solve(i+1,nums,target,n,dp);

        return dp[i][target] = take || notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return false;
        
        vector<vector<int>> dp(n, vector<int>((sum/2)+1,-1));
        return solve(0,nums,sum/2,n,dp);
    }
};