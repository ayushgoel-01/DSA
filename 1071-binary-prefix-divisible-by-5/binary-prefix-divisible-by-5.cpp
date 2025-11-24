class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();

        vector<bool> ans(n,false);
        int val = 0;

        for(int i=0; i<n; i++){
            val = (val * 1LL * 2 + nums[i]) % 5;
            if(val % 5 == 0) ans[i] = true;
        }
        return ans;
    }
};