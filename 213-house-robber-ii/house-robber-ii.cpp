class Solution {
private:
    int solve(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int take = nums[i] + solve(i+2,n,nums,dp);
        int notTake = solve(i+1,n,nums,dp);

        return dp[i] = max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp1(n+1,-1), dp2(n+1,-1);

        return max(solve(0,n-1,nums,dp1),solve(1,n,nums,dp2));
    }
};