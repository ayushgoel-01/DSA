class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i=1; i<n-1; i++){
            if(nums[i] == nums[i-1]) continue;
            int a = -1, b = -1;
            for(int j=i-1; j>=0; j--){
                if(nums[j] != nums[i]){
                    a = nums[j];
                    break;
                }
            }
            for(int j=i+1; j<n; j++){
                if(nums[j] != nums[i]){
                    b = nums[j];
                    break;
                }
            }
            if(a != -1 && b != -1){
                if(nums[i] > a && nums[i] > b && nums[i]) ans++;
                else if(nums[i] < a && nums[i] < b) ans++;
            }
        }
        return ans;
    }
};