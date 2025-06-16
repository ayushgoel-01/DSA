class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n = nums.size();
        long long mini = nums[0], maxi = nums[0];
        long long ans = 1LL * nums[0] * nums[m-1];

        for(int i=m-1; i<n; i++){
            mini = fmin(mini,nums[i-m+1]);
            maxi = fmax(maxi,nums[i-m+1]);
            ans = max({ans,nums[i] * maxi,nums[i] * mini});
        }
        return ans;
    }
};