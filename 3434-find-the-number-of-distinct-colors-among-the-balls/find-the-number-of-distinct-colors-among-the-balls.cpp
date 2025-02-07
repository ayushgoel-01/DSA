class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        vector<int> ans;
        
        unordered_map<int,int> mp;
        unordered_set<int> st;
        unordered_map<int,int> freq;

        for(int i=0; i<n; i++){
            int x = queries[i][0];
            int y = queries[i][1];

            if(mp.find(x) == mp.end()){
                mp[x] = y;
                st.insert(y);
            }
            else{
                int prev = mp[x];
                if(freq[prev] == 1) st.erase(prev);
                freq[prev]--;
                mp[x] = y;
                st.insert(y);
            }

            ans.push_back((int)st.size());
            freq[y]++;
        }
        return ans;
    }
};