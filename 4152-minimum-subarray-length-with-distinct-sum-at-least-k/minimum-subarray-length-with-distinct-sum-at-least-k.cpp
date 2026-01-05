class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int i = 0, j = 0, ans = INT_MAX;
        int sum = 0;

        while(j < n){
            if(mp.find(nums[j]) == mp.end()) sum += nums[j];
            mp[nums[j]]++;

            while(i < n && sum >= k){
                if(mp[nums[i]] > 1){
                    mp[nums[i]]--;
                }
                else{
                    sum -= nums[i];
                    mp.erase(nums[i]);
                }
                ans = min(ans,j-i+1);
                i++;
            }
            j++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};