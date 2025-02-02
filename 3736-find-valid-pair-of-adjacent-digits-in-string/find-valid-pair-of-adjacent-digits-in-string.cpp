class Solution {
public:
    string findValidPair(string s) {
        int n = s.size();

        unordered_map<char,int> mp;
        for(auto i: s) mp[i]++;

        string ans = "";
        for(int i=1; i<n; i++){
            char a = s[i-1];
            char b = s[i];

            if(a != b && (mp[a] == (a - '0')) && (mp[b] == (b - '0'))){
                ans += a;
                ans += b;
                break;
            }
        }
        return ans;
    }
};