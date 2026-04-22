class Solution {
#define P pair<int,pair<int,int>>
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        queue<P> q;
        vector<vector<int>> vis(n, vector<int>(m,0));

        auto cmp = [&](vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        };
        sort(sources.begin(),sources.end(),cmp);

        for(auto it: sources){
            vis[it[0]][it[1]] = it[2];
            q.push({it[0],{it[1],it[2]}});
        }

        int delrow[4] = {-1,0,1,0};
        int delcol[4] = {0,1,0,-1};

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto it = q.front();
                q.pop();
                int row = it.first;
                int col = it.second.first;
                int color = it.second.second;

                for(int i=0; i<4; i++){
                    int nrow = row + delrow[i];
                    int ncol = col + delcol[i];

                    if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                        vis[nrow][ncol] = color;
                        q.push({nrow,{ncol,color}});
                    }
                }
            }
        }
        return vis;
    }
};