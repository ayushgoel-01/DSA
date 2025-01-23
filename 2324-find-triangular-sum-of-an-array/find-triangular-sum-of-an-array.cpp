class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        int i = n-1;
        while(i > 0){
            for(int j=0; j<i; j++){
                nums[j] = (nums[j] + nums[j+1]) % 10;
            }
            i--;
        }
        return nums[0];
    }
};