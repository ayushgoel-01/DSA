class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;

        int odd1 = INT_MIN, even1 = INT_MIN;
        int odd2 = INT_MAX, even2 = INT_MAX;

        for(auto it: mp){
            if(it.second % 2 == 0){
                even1 = max(even1,it.second);
                even2 = min(even2,it.second);
            }
            else{
                odd1 = max(odd1,it.second);
                odd2 = min(odd2,it.second);
            }
        }
        return max(odd1-even2,odd2-even1);
    }
};