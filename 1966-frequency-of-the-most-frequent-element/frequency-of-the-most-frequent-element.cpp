class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());

        int l = 0, ans = 0;
        long sum = 0;

        for(int r=0; r<n; r++){
            sum += nums[r];
            long target = nums[r];

            while( (r-l+1) * target - sum > k ){
                sum -= nums[l];
                l++;
            }
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};