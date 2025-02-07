class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        vector<int> ans;
        
        unordered_map<int,int> mp;
        unordered_set<int> st;
        unordered_map<int,int> freq;

        for(int i=0; i<n; i++){
            int x = queries[i][0];          // Ball
            int y = queries[i][1];          // Color

            if(mp.find(x) == mp.end()){     // If ball is not colored, color it & insert color in set
                mp[x] = y;                  
                st.insert(y);
            }
            else{
                int prev = mp[x];            // If ball is already colored, find prev color

                if(freq[prev] == 1) st.erase(prev);
                freq[prev]--;               // Re-Coloring

                mp[x] = y;
                st.insert(y);
            }

            ans.push_back((int)st.size());
            freq[y]++;                      // Frequency of current color increases
        }
        return ans;
    }
};