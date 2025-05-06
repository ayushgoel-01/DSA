class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 && nums[0] == 1) return 1;

        bool flag = false;
        for(auto i: nums){
            if(i == 1){
                flag = true;
                break;
            }
        }

        int ans = flag ? 1 : 0, cnt = 1;
        for(int i=1; i<n; i++){
            if(nums[i] == 1 && nums[i] == nums[i-1]){
                cnt++;
                ans = max(ans,cnt);
            }
            else{
                cnt = 1;
            }
        }
        return ans;
    }
};