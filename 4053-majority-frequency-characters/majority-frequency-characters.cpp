class Solution {
public:
    string majorityFrequencyGroup(string s) {
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;

        unordered_map<int,int> mp2;
        for(auto it: mp){
            mp2[it.second]++;
        }

        int maxi = 0, f = 0;
        for(auto it: mp2){
            if(it.second > maxi){
                maxi = it.second;
                f = it.first;
            }
            else if(it.second == maxi){
                f = max(f,it.first);
            }
        }

        string ans = "";
        for(auto it: mp){
            if(it.second == f) ans += it.first;
        }
        return ans;
    }
};