class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int left = 0, right = n-1;
        int i = 0;
        while(i <= right){
            if(nums[i] == 0) swap(nums[i],nums[left++]);
            if(nums[i] == 2) swap(nums[i],nums[right--]);
            else i++;
        }
    }
};