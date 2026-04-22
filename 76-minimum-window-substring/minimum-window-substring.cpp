class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();

        unordered_map<char,int> mp;
        for(auto i: t) mp[i]++;

        int cnt = mp.size();
        int i = 0, j = 0, st = -1, len = INT_MAX;

        while(j < n){
            mp[s[j]]--;
            if(mp[s[j]] == 0) cnt--;

            while(cnt == 0){
                if(len > (j-i+1)){
                    st = i;
                    len = j-i+1;
                }
                mp[s[i]]++;
                if(mp[s[i]] >= 1) cnt++; 
                i++;
            }
            j++;
        }
        if(len == INT_MAX) return "";
        return s.substr(st,len);
    }
};