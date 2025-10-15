class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();

        vector<int> start(n,1), end(n,1);
        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                end[i] = end[i-1] + 1;
            }
        }
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                start[i] = start[i+1] + 1;
            }
        }

        int maxi = 0;
        for(int i=1; i<n; i++){
            maxi = max(maxi, min(end[i-1],start[i]));
        }
        return maxi;
    }
};