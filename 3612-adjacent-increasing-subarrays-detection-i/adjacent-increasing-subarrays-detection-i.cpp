class Solution {
private:
    bool solve(vector<int>& nums, int i, int j, int k){
        int n = nums.size();
        while(k > 1){
            if(nums[i] <= nums[i-1] || nums[j] <= nums[j-1]) return false;
            k--;
            i--; j--;
        }
        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        int j = 2*k-1;
        while(j < n){
            int i = j-k;
            if(solve(nums,i,j,k)) return true;
            j++;
        }
        return false;
    }
};