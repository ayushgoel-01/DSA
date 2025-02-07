class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();

        vector<int> ans;
        
        unordered_map<int,int> mp;
        unordered_map<int,int> freq;

        for(int i=0; i<n; i++){
            int x = queries[i][0];          // Ball
            int y = queries[i][1];          // Color

            if(mp.find(x) == mp.end()){     // If ball is not colored, color it & insert color in set
                mp[x] = y;                  
            }
            else{
                int prev = mp[x];            // If ball is already colored, find prev color

                freq[prev]--;               // Re-Coloring
                if(freq[prev] == 0) freq.erase(prev);

                mp[x] = y;
            }

            freq[y]++;                      // Frequency of current color increases
            ans.push_back((int)freq.size());
        }
        return ans;
    }
};