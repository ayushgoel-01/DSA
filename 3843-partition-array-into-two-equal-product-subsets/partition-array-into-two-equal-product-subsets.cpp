class Solution {
private:
    bool solve(int i, vector<int>& nums, long long p1, long long p2, long long target){
        if(p1 > target || p2 > target) return false;
        if(i >= nums.size()){
            return p1 == target && p2 == target;
        }

        bool op1 = false, op2 = false;
        op1 = solve(i+1,nums,1LL*p1*nums[i],p2,target);
        op2 = solve(i+1,nums,p1,1LL*p2*nums[i],target);

        return op1 || op2;
    }
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();

        long long p1 = 1, p2 = 1;
        return solve(0,nums,p1,p2,target);
    }
};