class Solution {
#define ll long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        ll sum1 = accumulate(grid[0].begin(),grid[0].end(),0LL);
        
        vector<ll> v(m,0);
        v[0] = grid[1][0];
        for(int j=1; j<m; j++){
            v[j] = v[j-1] + grid[1][j];
        }

        ll mini = LLONG_MAX;
        ll curr = 0;
        for(int j=0; j<m; j++){
            curr += grid[0][j];

            ll rem = sum1-curr;
            if(j-1 >= 0) rem = max(rem,v[j-1]);

            mini = min(mini,rem);
        }

        return mini;
    }
};