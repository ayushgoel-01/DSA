class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> ans(n-k+1, vector<int>(m-k+1,0));

        for(int i=0; i<n-k+1; i++){
            for(int j=0; j<m-k+1; j++){
                vector<int> v;

                for(int a=0; a<k; a++){
                    for(int b=0; b<k; b++){
                        v.push_back(grid[i+a][j+b]);
                    }
                }

                int val = INT_MAX;
                for(int a=0; a<v.size(); a++){
                    for(int b=0; b<v.size(); b++){
                        if(a == b || v[a] == v[b]) continue;
                        val = min(val,abs(v[a]-v[b]));
                    }
                }

                if(val == INT_MAX) ans[i][j] = 0;
                else ans[i][j] = val;
            }
        }
        return ans;
    }
};