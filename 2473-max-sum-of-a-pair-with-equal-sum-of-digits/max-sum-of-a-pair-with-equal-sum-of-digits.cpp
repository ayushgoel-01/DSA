class Solution {
private:
    int findSum(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int> mp;
        int ans = 0;

        for(int i=0; i<n; i++){
            int currSum = findSum(nums[i]);
            if(mp.find(currSum) != mp.end()){
                ans = max(ans,nums[i] + mp[currSum]);
                mp[currSum] = max(mp[currSum],nums[i]);
            }
            else mp[currSum] = nums[i];
        }
        return ans == 0 ? -1 : ans;
    }
};