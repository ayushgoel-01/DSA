class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> pref(n,0);
        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] += pref[i-1] + nums[i];
        }

        long long maxi = LLONG_MIN;
        for(int start=0; start<k; start++){
            long long curr = 0;
            int i = start;

            while(i < n && i+k-1 < n){
                int j = i+k-1;
                long long subarraySum = pref[j];
                if(i-1 >= 0) subarraySum -= pref[i-1];
                
                curr = max(subarraySum,curr+subarraySum);
                maxi = max(maxi,curr);
                i += k;
            }
        }
        return maxi;
    }
};