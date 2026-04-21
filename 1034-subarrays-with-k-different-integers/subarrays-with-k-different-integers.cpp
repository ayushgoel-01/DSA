class Solution {
private:
    int solve(vector<int>& nums, int k){
        int n = nums.size();

        unordered_map<int,int> mp;
        int i = 0, j = 0, ans = 0;

        while(j < n){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            if(mp.size() <= k) ans += j-i+1;
            j++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int val1 = solve(nums,k);
        int val2 = solve(nums,k-1);
        return val1 - val2;
    }
};