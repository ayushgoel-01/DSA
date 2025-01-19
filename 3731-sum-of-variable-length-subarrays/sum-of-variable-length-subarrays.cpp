class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n,0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = nums[i] + pref[i-1];
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            int start = max(0,i-nums[i]);
            ans += pref[i];
            
            if(start-1 >= 0) ans -= pref[start-1];
        }
        return ans;
    }
};