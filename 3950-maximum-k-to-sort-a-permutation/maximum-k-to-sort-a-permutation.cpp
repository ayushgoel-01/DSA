class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        bool taken = false;
        for(int i=0; i<n; i++){
            if(nums[i] != i){
                if(!taken) ans = nums[i];
                else ans = ans & nums[i];
                taken = true;
            }
        }
        return ans;
    }
};