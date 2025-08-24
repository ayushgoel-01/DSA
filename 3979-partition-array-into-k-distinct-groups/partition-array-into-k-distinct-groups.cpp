class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(n % k != 0) return false;

        int grp = n / k;
        
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;

        for(auto it: mp){
            if(it.second > grp) return false;
        }
        return true;
    }
};