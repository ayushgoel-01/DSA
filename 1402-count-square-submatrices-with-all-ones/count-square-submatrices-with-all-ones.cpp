class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> v(n, vector<int>(m,0));
        for(int i=0; i<n; i++) v[i][0] = matrix[i][0];
        for(int j=0; j<m; j++) v[0][j] = matrix[0][j];

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 1){
                    int val = min({v[i-1][j],v[i][j-1],v[i-1][j-1]});
                    v[i][j] = val+1;
                }
            }
        }

        int ans = 0;
        for(auto it: v){
            ans += accumulate(it.begin(),it.end(),0);
        }
        return ans;
    }
};