class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        vector<vector<char>> ans(m, vector<char>(n));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[j][i] = boxGrid[i][j];
            }
        }

        for(int i=0; i<m; i++){
            reverse(ans[i].begin(),ans[i].end());
        }

        for(int j=0; j<n; j++){
            int space = m-1;
            for(int i=m-1; i>=0; i--){
                if(ans[i][j] == '*'){
                    space = i-1;
                    continue;
                }
                if(ans[i][j] == '#'){
                    ans[i][j] = '.';
                    ans[space][j] = '#';
                    space--;
                }
            }
        }
        return ans;
    }
};