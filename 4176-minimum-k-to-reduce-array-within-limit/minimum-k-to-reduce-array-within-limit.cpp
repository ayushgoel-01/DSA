class Solution {
#define ll long long
private:
    int solve(vector<int>& nums, ll val){
        ll ans = 0;
        for(auto i: nums){
            ans += ceil(i/(double)val);
        }
        return ans;
    }
public:
    int minimumK(vector<int>& nums) {
        int n = nums.size();
        ll start = 1, end = *max_element(nums.begin(),nums.end())+100;

        ll ans = end;
        while(start <= end){
            ll mid = start + (end - start)/2;
            ll val = solve(nums,mid);

            if(val <= mid * 1LL * mid){
                ans = mid;
                end = mid-1;
            }
            else start = mid+1;
        }
        return ans;
    }
};