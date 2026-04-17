class Solution {
private:
    int reverse(int n){
        int ans = 0;
        while(n){
            ans = ans * 10 + (n%10);
            n = n / 10;
        }
        return ans;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        int ans = INT_MAX;
        for(int i=n-1; i>=0; i--){
            int rev = reverse(nums[i]);
            if(mp.find(rev) != mp.end()){
                ans = min(ans,abs(i-mp[rev]));
            }
            mp[nums[i]] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};