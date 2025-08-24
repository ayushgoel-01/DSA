class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 0;
        int i = 0, j = 0, zeroCnt = 0;

        while(j < nums.size()){
            if(nums[j] == 0) zeroCnt++;
            while(zeroCnt > 1){
                if(nums[i] == 0) zeroCnt--;
                i++;
            }
            maxi = max(maxi,j-i+1);
            j++;
        }
        return maxi-1;
    }
};