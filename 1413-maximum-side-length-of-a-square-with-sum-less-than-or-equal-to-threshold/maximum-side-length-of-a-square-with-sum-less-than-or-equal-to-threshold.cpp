class Solution {
private:
    int solve(vector<vector<int>>& pref, int i, int j, int r2, int c2){
        int sum = pref[r2][c2];
        if(i > 0) sum -= pref[i-1][c2];
        if(j > 0) sum -= pref[r2][j-1];
        if(i > 0 && j > 0) sum += pref[i-1][j-1];

        return sum;
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                pref[i][j] = mat[i][j] + (i > 0 ? pref[i-1][j] : 0) + (j > 0 ? pref[i][j-1] : 0)
                             - ((i > 0 && j > 0) ? pref[i-1][j-1] : 0);
            }
        }

        int best = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                for(int side=best; side<min(n-i,m-j); side++){
                    int r2 = i + side;
                    int c2 = j + side;

                    int sum = solve(pref,i,j,r2,c2);
                    if(sum <= threshold) best = max(best,side+1);
                    else break;
                }
            }
        }
        return best;
    }
};