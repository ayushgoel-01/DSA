class Solution {
private:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
public:
    string sortVowels(string s) {
        int n = s.size();
        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            if(mp.find(s[i]) == mp.end()) mp[s[i]] = i;
        }

        int a = 0, e = 0, i = 0, o = 0, u = 0;
        for(auto it: s){
            if(it == 'a') a++;
            else if(it == 'e') e++;
            else if(it == 'i') i++;
            else if(it == 'o') o++;
            else if(it == 'u') u++;
        }

        vector<pair<char,int>> v;
        v.push_back({'a',a});
        v.push_back({'e',e});
        v.push_back({'i',i});
        v.push_back({'o',o});
        v.push_back({'u',u});

        auto cmp = [&](pair<char,int>& a, pair<char,int>& b){
            if(a.second == b.second) return mp[a.first] < mp[b.first];
            return a.second > b.second;
        };
        sort(v.begin(),v.end(),cmp);
        int idx = 0;

        string ans = "";
        for(int i=0; i<n; i++){
            if(v[idx].second == 0) idx++;
            if(isVowel(s[i])){
                ans += v[idx].first;
                v[idx].second--;
            }
            else ans += s[i];
        }
        return ans;
    }
};