class Solution {
private:
    int solve(vector<int>& nums, int mid, int n){
        int sum = 0, cnt = 1;
        for(int i=0; i<n; i++){
            if(sum + nums[i] <= mid){
                sum += nums[i];
            }
            else{
                cnt++;
                sum = nums[i];
            }
        }
        return cnt;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int start = *max_element(weights.begin(),weights.end());
        int end = accumulate(weights.begin(),weights.end(),0);
        int ans = INT_MAX;

        while(start <= end){
            int mid = (start + end)/2;
            if(solve(weights,mid,n) <= days){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};