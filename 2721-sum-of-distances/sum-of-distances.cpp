class Solution {
#define ll long long
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();

        vector<ll> ans(n,0);
        unordered_map<int,ll> freq, sum;

        for(int i=0; i<n; i++){
            ll val = (freq[nums[i]] * i) - sum[nums[i]];
            ans[i] += val;
            freq[nums[i]]++;
            sum[nums[i]] += i;
        }

        freq.clear();
        sum.clear();

        for(int i=n-1; i>=0; i--){
            ll val = sum[nums[i]] - (freq[nums[i]] * i);
            ans[i] += val;
            freq[nums[i]]++;
            sum[nums[i]] += i;
        }
        return ans;
    }
};