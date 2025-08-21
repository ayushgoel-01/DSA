class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<int> height(m,0);
        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) height[j] = 0;
                else height[j]++;
            }

            for(int j=0; j<m; j++){
                int mini = height[j];
                for(int k=j; k>=0; k--){
                    mini = min(mini,height[k]);
                    ans += mini;
                }
            }
        }
        return ans;
    }
};
