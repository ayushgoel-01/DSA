class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(auto it: nums){
            string s = to_string(it);
            for(auto j: s){
                ans.push_back(j - '0');
            }
        }
        return ans;
    }
};