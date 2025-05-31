class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        vector<vector<bool>> vis(n+1, vector<bool>(n+1,false));
        queue<int> q;
        q.push(1);

        int ans = 0;
        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto top = q.front();
                q.pop();

                if(top == n*n) return ans;


                for(int i=1; i<=6; i++){
                    int val = top + i;
                    if(val > n*n) break;

                    int a = (val-1) % n;
                    int b = (val-1) / n;
                    bool leftToRight = (b % 2 == 0) ? true : false;

                    int row = n-b-1, col = 0;

                    if(leftToRight){
                        col = a;
                    }
                    else col = n - a - 1;

                    if(vis[row][col]) continue;

                    if(board[row][col] != -1){
                        q.push(board[row][col]);
                    }
                    else{
                        q.push(val);
                    }
                    vis[row][col] = true;
                }
            }
            ans++;
        }
        return -1;
    }
};