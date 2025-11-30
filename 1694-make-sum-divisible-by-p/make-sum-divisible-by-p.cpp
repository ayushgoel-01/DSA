class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        long long sum = accumulate(nums.begin(),nums.end(),0LL);
        int target = sum % p;
        if(target == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;
        int curr = 0, ans = n;

        for(int i=0; i<n; i++){
            curr = (curr + nums[i]) % p;
            int rem = (curr - target + p) % p;

            if(mp.find(rem) != mp.end()){
                ans = min(ans,i - mp[rem]);
            }
            mp[curr] = i;
        }
        return (ans == n) ? -1 : ans;
    }
};