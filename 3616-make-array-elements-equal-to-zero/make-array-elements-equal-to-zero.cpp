class Solution {
private:
    bool solve(vector<int> nums, int idx, bool left){
        int n = nums.size();

        int i = idx;
        while(i >= 0 && i < n){
            if(nums[i] == 0){
                if(left) i--;
                else i++;
            }
            else if(nums[i] > 0){
                nums[i]--;
                left = !left;
                if(left) i--;
                else i++;
            }
        }
        for(auto i: nums){
            if(i != 0) return false;
        }
        return true;
    }
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        for(int i=0; i<n; i++){
            if(nums[i] != 0) continue;
            if(solve(nums,i,true)) ans++;
            if(solve(nums,i,false)) ans++;
        }
        return ans;
    }
};