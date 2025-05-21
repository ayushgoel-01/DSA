class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> v(n, vector<int>(m,0));

        int delrow[3] = {-1,0,1};
        int delcol[3] = {-1,0,1};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt = 0;

                for(int a=0; a<3; a++){
                    for(int b=0; b<3; b++){
                        int nrow = i + delrow[a];
                        int ncol = j + delcol[b];

                        if(nrow == i && ncol == j) continue;

                        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                        board[nrow][ncol] == 1){
                            cnt++;
                        }
                    }
                }
                v[i][j] = cnt;
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 0){
                    board[i][j] = (v[i][j] == 3) ? 1 : 0;
                }
                else{
                    if(v[i][j] < 2 || v[i][j] > 3) board[i][j] = 0;
                    else board[i][j] = 1;
                }
            }
        }

    }
};