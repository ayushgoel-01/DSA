class Solution {
#define ll long long
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        ll cnt = 0;
        unordered_map<ll,ll> mp;
        for(int i=0; i<n; i++){
            ll val = i - nums[i];
            cnt += mp[val];
            mp[val]++;
        }

        ll total = n * 1LL * (n-1)/2;
        return total - cnt;
    }
};