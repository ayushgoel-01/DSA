class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();

        int ans = nums[0];
        nums[0] = 1e9;
        sort(nums.begin(),nums.end());
        ans += nums[0];
        ans += nums[1];

        return ans;
    }
};