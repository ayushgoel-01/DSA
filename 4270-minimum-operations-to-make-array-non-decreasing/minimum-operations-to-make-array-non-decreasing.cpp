class Solution {
public:
    long long minOperations(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0, maxi = nums[0], val = 0;
        for(int i=1; i<n; i++){
            if(nums[i] + val < maxi){
                ans += maxi - (nums[i] + val);
                long long newAdd = maxi - (nums[i] + val);
                val += newAdd;
            }
            maxi = max(maxi,(long long)nums[i] + val);
        }
        return ans;
    }
};