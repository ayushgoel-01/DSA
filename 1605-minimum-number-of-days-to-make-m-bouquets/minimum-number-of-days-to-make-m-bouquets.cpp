class Solution {
private:
    bool solve(vector<int>& nums, int m, int k, int mid){
        int n = nums.size();
        int val = 0, cnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] <= mid){
                cnt++;
            }
            else cnt = 0;
            if(cnt >= k){
                val++;
                cnt = 0;
            }
        }
        return val >= m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(m * 1LL * k > n) return -1;

        int start = *min_element(bloomDay.begin(),bloomDay.end());
        int end = *max_element(bloomDay.begin(),bloomDay.end());
        int ans = 0;

        while(start <= end){
            int mid = start + (end-start)/2;
            if(solve(bloomDay,m,k,mid)){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};