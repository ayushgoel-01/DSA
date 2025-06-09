class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());

        int ans = 0;
        for(auto i: nums){
            int val = i;
            while(st.count(val) >= 1){
                val--;
            }

            int cnt = 0;
            while(st.count(val+1) >= 1){
                st.erase(val);
                val++;
                cnt++;
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};