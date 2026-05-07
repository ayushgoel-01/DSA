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
            for(int i=m-1; i>=0; i--){

                if(ans[i][j] == '.'){
                    bool got = true;
                    int k = i-1;
                    while(k >= 0 && ans[k][j] != '#'){
                        if(ans[k][j] == '*'){
                            got = false;
                            i = k;
                            break;
                        }
                        k--;
                    }

                    if(got && k >= 0){
                        ans[i][j] = '#';
                        ans[k][j] = '.';
                    }
                }
            }
        }
        return ans;
    }
};