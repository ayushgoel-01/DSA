class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        pair<int,int> v[m*n+1];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                v[mat[i][j]] = {i,j};
            }
        }

        vector<int> row(n,0) , col(m,0);

        for(int i=0; i<n*m; i++){
            int r = v[arr[i]].first;
            int c = v[arr[i]].second;
            row[r]++;
            col[c]++;

            if(row[r] >= m || col[c] >= n) return i;
        }
        return n*m;
    }
};