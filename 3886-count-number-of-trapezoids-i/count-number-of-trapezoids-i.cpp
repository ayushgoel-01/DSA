class Solution {
int mod = 1e9 + 7;
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> mp;
        for(auto it: points) mp[it[1]]++;

        int ans = 0, prevTotal = 0;
        for(auto& it: mp){
            int cnt = it.second;
            long long lines = cnt * 1LL * (cnt-1)/2;     
            ans = (ans + lines * prevTotal)%mod;

            prevTotal += lines;
        }
        return ans;
    }
};