class Solution {
int mod = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        unordered_map<int,int> left, right;

        for(auto i: nums) right[i]++;

        for(int i=0; i<n; i++){
            right[nums[i]]--;
            int val = 2 * nums[i];

            if(left.find(val) != left.end() && right.find(val) != right.end()){
                ans = (ans + (left[val] * 1LL * right[val])%mod)%mod;
            }
            left[nums[i]]++;
        }
        return ans;
    }
};