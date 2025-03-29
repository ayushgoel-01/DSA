class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<char,int> mp;
        for(auto i: nums) mp[i]++;

        for(auto it: mp){
            if(it.second % 2 != 0) return false;
        }
        return true;
    }
};