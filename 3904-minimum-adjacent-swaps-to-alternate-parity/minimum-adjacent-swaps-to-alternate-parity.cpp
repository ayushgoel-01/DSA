class Solution {
private:
    int solve(vector<int>& nums, int state){
        int n = nums.size();

        int ans = 0, curr = 0;
        for(int i=0; i<n; i++){
            if(nums[i] % 2 == state){
                ans += abs(i - curr);
                curr += 2;
            }
        }
        return ans;
    }
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int odd = 0, even = 0;
        for(auto i: nums){
            if(i % 2 == 0) even++;
            else odd++;
        }

        if(abs(even-odd) > 1) return -1;

        if(even > odd) return solve(nums,0);
        else if(odd > even) return solve(nums,1);
        else return min(solve(nums,0),solve(nums,1));
    }
};