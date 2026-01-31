class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto it: trips){
            mp[it[1]] += it[0];
            mp[it[2]] -= it[0];
        }

        int curr = 0;
        for(auto it: mp){
            curr += it.second;
            if(curr > capacity) return false;
        }
        return true;
    }
};