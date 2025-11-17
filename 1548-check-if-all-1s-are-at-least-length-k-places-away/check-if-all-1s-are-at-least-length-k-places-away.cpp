class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, cnt = 0;
        while(i < n && nums[i] != 1) i++;
        i++;

        while(i < n){
            if(nums[i] == 1 && cnt < k) return false;
            else if(nums[i] == 1) cnt = 0;
            else cnt++;
            i++;
        }
        return true;
    }
};