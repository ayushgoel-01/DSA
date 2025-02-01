class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0, val = 0;
        for(auto i: nums) val += (i == k);
        ans = val;

        for(int i=1; i<=50; i++){
            if(i == k) continue;

            int cnt = 0, maxi = 0;

            for(auto num: nums){
                if(cnt < 0) cnt = 0;

                if(num == i) cnt++;
                else if(num == k) cnt--;

                maxi = max(maxi,cnt);
            }
            ans = max(ans,val+maxi);
        }
        return ans;
    }
};