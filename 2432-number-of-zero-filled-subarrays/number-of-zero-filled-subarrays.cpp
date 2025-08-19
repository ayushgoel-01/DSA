class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        int i = 0, cnt = 0;

        while(i < n){
            while(i < n && nums[i] == 0){
                cnt++;
                i++;
            }

            ans += (cnt * 1LL * (cnt+1))/2;
            cnt = 0;
            i++;
        }
        ans += (cnt * (cnt+1))/2;
        return ans;
    }
};