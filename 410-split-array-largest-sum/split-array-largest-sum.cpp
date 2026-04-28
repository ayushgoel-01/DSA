class Solution {
private:
    int solve(vector<int>& nums, int k, int mid){
        int n = nums.size();
        int ans = 1, sum = 0;
        for(int i=0; i<n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                ans++;
                sum = nums[i];
            }
        }
        return ans;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        int start = *max_element(nums.begin(),nums.end());
        int end = accumulate(nums.begin(),nums.end(),0LL);
        int ans = end;

        while(start <= end){
            int mid = start + (end-start)/2;
            int part = solve(nums,k,mid);

            if(part <= k){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};