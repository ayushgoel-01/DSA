class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> v(matrix.begin(),matrix.end());
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = v[j][i];
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};