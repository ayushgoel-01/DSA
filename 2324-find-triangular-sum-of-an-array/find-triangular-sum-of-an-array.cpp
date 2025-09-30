class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int size = n;

        while(size > 1){
            for(int i=1; i<n; i++){
                nums[i-1] = (nums[i] + nums[i-1]) % 10;
            }
            size--;
        }
        return nums[0];
    }
};