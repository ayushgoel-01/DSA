class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    string sortVowels(string s) {
        int n = s.size();

        unordered_map<char,int> mp, freq;
        for(int i=0; i<n; i++){
            if(isVowel(s[i]) && mp.find(s[i]) == mp.end()) mp[s[i]] = i;
            if(isVowel(s[i])) freq[s[i]]++;
        }

        vector<pair<char,int>> v;
        for(auto it: freq){
            v.push_back({it.first,it.second});
        }

        auto cmp = [&](pair<char,int>& a, pair<char,int>& b){
            if(a.second == b.second) return mp[a.first] < mp[b.first];
            return a.second > b.second;
        };
        sort(v.begin(),v.end(),cmp);

        int idx = 0;
        string ans = "";

        for(int i=0; i<n; i++){
            if(isVowel(s[i])){
                ans += v[idx].first;
                v[idx].second--;
                if(v[idx].second == 0) idx++;
            }
            else ans += s[i];
        }
        return ans;
    }
};