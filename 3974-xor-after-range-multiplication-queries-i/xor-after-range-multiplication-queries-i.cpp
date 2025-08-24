class Solution {
int mod = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for(auto& it: queries){
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];

            int idx = l;
            while(idx <= r){
                nums[idx] = (nums[idx] * 1LL * v) % mod;
                idx += k;
            }
        }

        int ans = 0;
        for(auto i: nums) ans = ans ^ i;
        return ans;
    }
};