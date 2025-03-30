class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();

        unordered_map<char,int> mp;
        for(int i=0; i<n; i++){
            mp[s[i]] = i;
        }

        vector<int> ans;
        int last = 0, pi = 0;
        for(int i=0; i<n; i++){
            last = max(last,mp[s[i]]);

            if(i >= last){
                if(!ans.empty()) ans.push_back(i - pi);
                else ans.push_back(i+1);
                pi = i;
                last = 0;
            }
        }
        return ans;
    }
};