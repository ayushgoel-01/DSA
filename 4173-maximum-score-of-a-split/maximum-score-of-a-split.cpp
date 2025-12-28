class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();

        vector<long long> pref(n,0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }

        long long mini = INT_MAX, maxi = LLONG_MIN;
        long long total = accumulate(nums.begin(),nums.end(),0LL);

        for(int i=n-1; i>=0; i--){
            maxi = max(maxi,pref[i]-mini);
            mini = min(mini,(long long)nums[i]);
        }
        return maxi;
    }
};