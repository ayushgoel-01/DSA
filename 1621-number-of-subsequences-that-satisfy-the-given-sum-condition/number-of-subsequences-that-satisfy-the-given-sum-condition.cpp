class Solution {
int mod = 1e9 + 7;
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        vector<int> power(n,0);
        power[0] = 1;

        for(int i=1; i<n; i++){
            power[i] = (power[i-1] * 2) % mod;
        }

        int l = 0, r = n-1, ans = 0;
        while(l <= r){
            if(nums[l] + nums[r] <= target){
                ans = (ans + power[r-l]) % mod;
                l++;
            }
            else r--;
        }
        return ans;
    }
};