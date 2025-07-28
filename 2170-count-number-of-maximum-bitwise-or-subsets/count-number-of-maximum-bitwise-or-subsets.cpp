class Solution {
private:
    int solve(int i, vector<int>& nums, int curr, int target){
        if(i >= nums.size()){
            return curr == target;
        }

        int take = solve(i+1,nums,curr|nums[i],target);
        int notTake = solve(i+1,nums,curr,target);

        return take + notTake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();

        int val = 0;
        for(auto i: nums){
            val = val | i;
        }
        cout<<val;
        return solve(0,nums,0,val);
    }
};