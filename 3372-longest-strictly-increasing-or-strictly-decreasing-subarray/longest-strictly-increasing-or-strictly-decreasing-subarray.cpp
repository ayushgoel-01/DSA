class Solution {
private:
    int increasing(vector<int>& nums, int n){
        int ans = 1;
        for(int i=1; i<n; i++){
            int cnt = 1;
            for(int j=i; j<n; j++){
                if(nums[j] > nums[j-1]){
                    cnt++;
                    ans = max(ans,cnt);
                }
                else break;
            }
        }
        return ans;
    }
    int decreasing(vector<int>& nums, int n){
        int ans = 1;
        for(int i=1; i<n; i++){
            int cnt = 1;
            for(int j=i; j<n; j++){
                if(nums[j] < nums[j-1]){
                    cnt++;
                    ans = max(ans,cnt);
                }
                else break;
            }
        }
        return ans;
    }
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        return max(increasing(nums,n),decreasing(nums,n));
    }
};