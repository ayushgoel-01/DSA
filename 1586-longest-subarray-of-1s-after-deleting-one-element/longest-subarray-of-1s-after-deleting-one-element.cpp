class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int i = 0, j = 0, ans = 0, zero = 0;
        while(j < n){
            if(nums[j] == 0) zero++;
            while(i < n && zero >= 2){
                if(nums[i] == 0) zero--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans-1;
    }
};