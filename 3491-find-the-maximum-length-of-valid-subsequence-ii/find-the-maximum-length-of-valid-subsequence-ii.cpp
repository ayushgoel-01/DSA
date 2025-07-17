class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = 1;
        vector<vector<int>> dp(n, vector<int>(k,1));
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int mod = (nums[i] + nums[j]) % k;

                dp[i][mod] = max(dp[i][mod],1 + dp[j][mod]);
                maxi = max(maxi,dp[i][mod]);
            }
        }
        return maxi;
    }
};