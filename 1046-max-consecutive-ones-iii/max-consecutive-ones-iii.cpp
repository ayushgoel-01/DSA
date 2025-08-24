class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0, j = 0, zeroCnt = 0, ans = 0;
        while(j < n){
            if(nums[j] == 0) zeroCnt++;
            while(i < n && zeroCnt > k){
                if(nums[i] == 0) zeroCnt--;
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};