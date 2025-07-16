class Solution {
private:
    int solve(int i, vector<int>& nums, int prev, int rem, vector<vector<vector<int>>>& dp){
        if(i >= nums.size()) return 0;

        if(dp[i][prev][rem] != -1) return dp[i][prev][rem];
        
        int take = INT_MIN, notTake = INT_MIN;

        if((prev + nums[i]) % 2 == rem ){
            take = max(take, 1 + solve(i+1,nums,(nums[i]%2==0?0:1),rem,dp));
        }

        notTake = max(notTake,solve(i+1,nums,prev,rem,dp));
        return dp[i][prev][rem] = max(take,notTake);
    }
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));

        int ans = 0;
        for(int i=0; i<n; i++){
            int prev = (nums[i] % 2 == 0) ? 0 : 1;
            ans = max({ans,solve(i+1,nums,prev,0,dp),solve(i+1,nums,prev,1,dp)});
        }
        return ans + 1;
    }
};