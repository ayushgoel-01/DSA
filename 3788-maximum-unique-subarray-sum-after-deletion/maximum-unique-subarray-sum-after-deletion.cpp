class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        unordered_set<int> st;
        int ans = 0;
        bool pos = false;
        for(auto i: nums){
            if(st.count(i) > 0 || i <= 0) continue;
            else{
                pos = true;
                ans += i;
                st.insert(i);
            }
        }
        if(!pos){
            ans = INT_MIN;
            for(auto i: nums) ans = max(ans,i);
        }
        return ans;
    }
};