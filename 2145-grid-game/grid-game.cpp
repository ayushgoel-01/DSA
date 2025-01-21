class Solution {
#define ll long long
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Total sum of row 1
        ll sum1 = accumulate(grid[0].begin(),grid[0].end(),0LL);
        ll sum2 = 0;

        ll ans = LLONG_MAX;
        for(int j=0; j<m; j++){
            sum1 -= grid[0][j];

            ll rem = max(sum1,sum2);
            ans = min(ans,rem);

            sum2 += grid[1][j];
        }
        return ans;
    }
};