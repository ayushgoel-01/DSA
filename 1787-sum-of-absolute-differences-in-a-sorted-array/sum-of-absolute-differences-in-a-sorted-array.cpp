class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> pref(n,0), suff(n,0);

        pref[0] = nums[0];
        for(int i=1; i<n; i++){
            pref[i] = pref[i-1] + nums[i];
        }

        suff[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            suff[i] = suff[i+1] + nums[i];
        }

        vector<int> ans(n,0);
        for(int i=0; i<n; i++){
            int val1 = (i-1 >= 0) ? pref[i-1] : 0;
            int val2 = (i+1 < n) ? suff[i+1] : 0;
            
            int len1 = i;
            int len2 = n-i-1;

            if(val1) ans[i] = ((nums[i] * len1) - val1);
            if(val2) ans[i] += (val2 - (nums[i] * len2));
        }
        return ans;
    }
};