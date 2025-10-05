class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        vector<int> dp(n,1), hash(n);
        int maxi = 1, maxIdx = 0;
        for(int i=0; i<n; i++){
            hash[i] = i;
            for(int prev=0; prev<i; prev++){
                if(nums[i] % nums[prev] == 0 && 1 + dp[prev] > dp[i]){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
            }
            if(dp[i] >= maxi){
                maxi = dp[i];
                maxIdx = i;
            }
        }

        vector<int> ans;
        ans.push_back(nums[maxIdx]);
        while(hash[maxIdx] != maxIdx){
            maxIdx = hash[maxIdx];
            ans.push_back(nums[maxIdx]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};