class Solution {
unordered_map<string,bool> dp;
private:
    bool solve(int i, string curr, string next, unordered_map<string,vector<char>>& mp){
        if(curr.size() == 1) return true;
        if(i+1 == curr.size()) return solve(0,next,"",mp);

        string key = to_string(i) + curr + next;
        if(dp.find(key) != dp.end()) return dp[key];

        string s = curr.substr(i,2);
        if(mp.find(s) == mp.end()) return false;

        for(auto& it: mp[s]){
            next += it;
            if(solve(i+1,curr,next,mp)) return true;
            next.pop_back();
        }
        return dp[key] = false;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();

        unordered_map<string,vector<char>> mp;
        for(auto it: allowed){
            string s = it.substr(0,2);
            mp[s].push_back(it[2]);
        }
        return solve(0,bottom,"",mp);
    }
};